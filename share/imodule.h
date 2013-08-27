#ifndef IMODULE_H
#define IMODULE_H

#include "corelib_global.h"

class Workspace;

// Интерфейс модуля
class CORELIB_EXPORT IModule
{
public:
	virtual	bool	initialize( Workspace & ) = 0;
	virtual	QString	name() const = 0;
	virtual	QString	version() const = 0;
	virtual	QStringList	depends() const = 0;
};

Q_DECLARE_INTERFACE( IModule, "com.modprg.IModule/1.0" )

#endif // IMODULE_H
