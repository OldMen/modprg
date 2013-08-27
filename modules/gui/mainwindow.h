#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QScopedPointer>
#include "imainwindow.h"

class MainWindowImpl;

class MainWindow : public QObject, public IMainWindow
{
	Q_OBJECT
	Q_INTERFACES( IMainWindow )
public:
	explicit MainWindow();
    virtual ~MainWindow();
	
	void	show();
	void	hide();

	void	addWindow( QWidget *w );
	void	removeWindow( QWidget *w );

private:
	QScopedPointer<MainWindowImpl>	m_mw;
};

#endif
