#include "mainwindow.h"
#include "mainwindowimpl.h"
#include <QDebug>
#include <QMdiSubWindow>

MainWindow::MainWindow()
	: QObject( 0 ), m_mw( new MainWindowImpl )
{
	m_mw->show();
}

MainWindow::~MainWindow()
{
}

void MainWindow::show()
{
	m_mw->show();
}

void MainWindow::hide()
{
	m_mw->hide();
}

void MainWindow::addWindow( QWidget *w )
{
	QMdiSubWindow *sub = m_mw->m_mdiArea->addSubWindow( w );
	sub->show();
}

void MainWindow::removeWindow( QWidget *w )
{
	m_mw->m_mdiArea->removeSubWindow( w );
}
