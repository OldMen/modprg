#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include "ilogger.h"

class Workspace;
class QTextBrowser;

class Logger : public QObject, public ILogger
{
	Q_OBJECT
	Q_INTERFACES( ILogger )
public:
	explicit Logger( const Workspace &ws );
	virtual ~Logger();
	
	void	log( const QString &str );

private slots:
	void	post_init();

private:
	const	Workspace	&m_ws;
	QTextBrowser		*m_browser;
};

#endif
