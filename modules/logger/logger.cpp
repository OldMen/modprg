#include "logger.h"
#include "workspace.h"
#include "imainwindow.h"
#include <QTextBrowser>
#include <QDateTime>
#include <QDebug>

Logger::Logger( const Workspace &ws )
	: QObject( 0 ), m_ws( ws )
{
	m_browser = new QTextBrowser;
	m_browser->setMinimumSize( 500, 300 );
	m_browser->setWindowTitle( "Logger" );
	
	QMetaObject::invokeMethod( this, "post_init", Qt::QueuedConnection );
}

Logger::~Logger()
{
}

void Logger::log( const QString &str )
{
	m_browser->append( "[" + QDateTime::currentDateTime().toString() + "] " + str );
}

void Logger::post_init()
{
	IMainWindow *mw = m_ws.service<IMainWindow>();
	if( mw )
		mw->addWindow( m_browser );
}
