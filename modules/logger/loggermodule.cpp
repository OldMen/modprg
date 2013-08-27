#include "loggermodule.h"
#include "logger.h"
#include "workspace.h"
#include <QStringList>
#include <QtPlugin>

bool LoggerModule::initialize( Workspace &ws )
{
	ws.regService( "Logger", new Logger( ws ) );
	return true;
}

QString LoggerModule::name() const
{
	return "logger";
}

QString LoggerModule::version() const
{
	return "0.0.1";
}

QStringList LoggerModule::depends() const
{
	return QStringList();
}

Q_EXPORT_PLUGIN2( logger, LoggerModule )
