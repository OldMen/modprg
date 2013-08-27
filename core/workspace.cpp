#include "workspace.h"
#include <QDebug>

void Workspace::regService( const QString &name, Interface *iface )
{
	QWriteLocker lock( &m_mutex );

	if( m_ifaces.contains( name ) )
	{
		qWarning() << "[Workspace::regService] Service already registration" << name;
		return;
	}
	
	m_ifaces[ name ] = QSharedPointer<Interface>( iface );
}

void Workspace::unregService( const QString &name )
{
	QWriteLocker lock( &m_mutex );
	m_ifaces.remove( name );
}

void Workspace::dump() const
{
	QReadLocker lock( &m_mutex );
	qDebug() << "Registration services: " << m_ifaces.keys();
}
