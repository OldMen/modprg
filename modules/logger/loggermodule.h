#ifndef LOGGERPLUGIN_H
#define LOGGERPLUGIN_H

#include <QObject>
#include "imodule.h"

class LoggerModule : public QObject, public IModule
{
	Q_OBJECT
	Q_INTERFACES( IModule )
public:
	bool	initialize( Workspace &ws );
	QString	name() const;
	QString	version() const;
	QStringList	depends() const;
};

#endif // LOGGERPLUGIN_H
