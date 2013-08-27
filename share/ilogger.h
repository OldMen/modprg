#ifndef ILOGGER_H
#define ILOGGER_H

#include "corelib_global.h"
#include "interface.h"

class CORELIB_EXPORT ILogger : public Interface
{
public:
	virtual	void	log( const QString &str ) = 0;
};

Q_DECLARE_INTERFACE( ILogger, "com.modprg.ILogger/1.0" )

#endif // ILOGGER_H
