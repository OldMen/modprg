#include "guimodule.h"
#include "mainwindow.h"
#include "workspace.h"
#include "ilogger.h"
#include <QStringList>
#include <QtPlugin>
#include <QDebug>

bool GuiModule::initialize( Workspace &ws )
{
	ILogger *log = ws.service<ILogger>();
	if( !log )
	{
		qWarning() << "Error: Logger not initialized.";
		return false;
	}
	
	log->log( "Create main window" );
	MainWindow *mw = new MainWindow;

	log->log( "Registration MainWindow interface" );
	ws.regService( "MainWindow", mw );

	return true;
}

QString GuiModule::name() const
{
	return "gui";
}

QString GuiModule::version() const
{
	return "0.0.1";
}

QStringList GuiModule::depends() const
{
	return QStringList() << "logger";
}

Q_EXPORT_PLUGIN2( gui, GuiModule )
