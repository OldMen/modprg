#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QMap>
#include <QSharedPointer>
#include <QReadWriteLock>
#include "interface.h"

class QStringList;

class Workspace
{
	typedef QSharedPointer<Interface>	InterfacePtr;

public:
	void	regService( const QString &name, Interface *iface );
	void	unregService( const QString &name );

	template<typename T> T  *service( const QString &name = QString() ) const;

	QStringList	services() const;
	
private:
	typedef QMap< QString, InterfacePtr >	InterfaceMap;
	InterfaceMap	m_ifaces;
	mutable QReadWriteLock	m_mutex;
};

template<typename T>
T* Workspace::service( const QString &name ) const
{
	QReadLocker lock( &m_mutex );
	for( InterfaceMap::ConstIterator it = m_ifaces.constBegin(); it != m_ifaces.constEnd(); ++it )
	{
		T *iface = dynamic_cast< T* >( it.value().data() );
		if( !iface )
			continue;
	
		if( name.isNull() )
			return iface;

		if( it.key() == name )
			return iface;
	}

	return 0;
}


#endif // WORKSPACE_H
