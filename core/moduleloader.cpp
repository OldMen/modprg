#include "moduleloader.h"
#include "imodule.h"
#include <QPluginLoader>
#include <QDirIterator>
#include <QStringList>
#include <QSharedPointer>
#include <QDebug>

class ModuleLoader::Priv
{
public:
	class Pusher
	{
	public:
		explicit Pusher( const QString &name, ModuleLoader &ml ) : m_stack( ml.m_d->m_initStack )
		{
			m_stack.push_back( name );
		}
	
		~Pusher()
		{
			m_stack.pop_back();
		}
		
	private:
		QStringList		&m_stack;
	};
	
	
	typedef QSharedPointer<QPluginLoader>		PluginLoaderPtr;
	typedef QPair<IModule*, PluginLoaderPtr>	ModuleInstance;
	
	QMap<QString, ModuleInstance>				m_loadedModules;
	QStringList									m_initStack;
	QStringList									m_initializedModules;
};

ModuleLoader::ModuleLoader()
	: QObject( 0 ), m_d( new Priv )
{
}

ModuleLoader::~ModuleLoader()
{
}

QStringList ModuleLoader::initializedModules() const
{
	return m_d->m_initializedModules;
}

void ModuleLoader::initAll( Workspace &ws )
{
	m_d->m_initializedModules.clear();
	
	QStringList modules = allModulePaths();
	qDebug() << "Available modules:" << modules;
	
	// Загружаем все модули в память и получаем их instance
	foreach( const QString &filePath, modules )
	{
		Priv::PluginLoaderPtr mod( new QPluginLoader( filePath ) );
		QObject *modIns = mod->instance();
		if( modIns )
		{
			IModule *modIface = qobject_cast< IModule* >( modIns );
			if( modIface )
				m_d->m_loadedModules[ modIface->name() ] = qMakePair( modIface, mod );
		}
		else
		{
			qDebug() << "Error loading module:" << mod->errorString();
		}
	}

	// Инициализируем загруженные модули
	foreach( const QString &name, m_d->m_loadedModules.keys() )
	{
		if( !initModule( name, ws ) )
			qWarning() << "Error initialize module:" << name;
	}

	m_d->m_loadedModules.clear();
}

QStringList ModuleLoader::allModulePaths() const
{
	QStringList plugins;
	QStringList paths;
	paths << "modules" << "build/modules";

	foreach( const QString &path, paths )
	{
		QDirIterator it( path, QDir::NoFilter, QDirIterator::Subdirectories );
		while( it.hasNext() )
		{
			QString filePath = it.next();
			if( QLibrary::isLibrary( filePath ) )
				plugins += filePath;
		}
	}

	return plugins;
}

bool ModuleLoader::initModule( const QString &name, Workspace &ws )
{
	// Проверяем циклические зависимости
	if( m_d->m_initStack.contains( name ) )
	{
		qWarning() << "Cyclic dependency:";
		qWarning() << m_d->m_initStack;
		return false;
	}
	
	Priv::Pusher p( name, *this );
	
	// Если модуль уже инициализирован - выходим
	if( m_d->m_initializedModules.contains( name ) )
		return true;

	// Проверяем есть ли такой модуль в числе загруженных?
	if( !m_d->m_loadedModules.contains( name ) )
	{
		qWarning() << "Module not available:" << name;
		return false;
	}
	
	IModule *mod = m_d->m_loadedModules[ name ].first;
	
	// Вначале инициализируем модули от которых зависит заданный
	foreach( const QString &name, mod->depends() )
	{
		if( !initModule( name, ws ) )
			return false;
	}
	
	// Инициализируем заданный модуль
	bool res = mod->initialize( ws );
	if( res )
		m_d->m_initializedModules.append( name );
	
	return res;
}
