#ifndef IMAINWINDOW_H
#define IMAINWINDOW_H

#include "corelib_global.h"
#include "interface.h"

class QWidget;
class CORELIB_EXPORT IMainWindow : public Interface
{
public:
	virtual	void	show() = 0;
	virtual	void	hide() = 0;
	
	virtual	void	addWindow( QWidget *w ) = 0;
	virtual	void	removeWindow( QWidget *w ) = 0;
};

Q_DECLARE_INTERFACE( IMainWindow, "com.modprg.IMainWindow/1.0" )

#endif // IMAINWINDOW_H
