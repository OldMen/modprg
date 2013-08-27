#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QObject>
#include <QScopedPointer>
#include "corelib_global.h"

class Workspace;
class QStringList;

class CORELIB_EXPORT ModuleLoader : public QObject
{
	Q_OBJECT
	Q_DISABLE_COPY( ModuleLoader );
public:
    ModuleLoader();
    virtual ~ModuleLoader();

	virtual void		initAll( Workspace &ws );

	QStringList			initializedModules() const;
	
protected:
	/**
	 * @brief Метод возвращает список всех обнаруженных файлов-модулей.
	 *
	 * @return QStringList список обнаруженных модулей
	 **/
	QStringList	allModulePaths() const;

	bool		initModule( const QString &name, Workspace &ws );

private:
	class Priv;
	QScopedPointer<Priv>	m_d;
};

#endif // PLUGINMANAGER_H
