#ifndef GUIPLUGIN_H
#define GUIPLUGIN_H

#include <QObject>
#include "imodule.h"

class GuiModule : public QObject, public IModule
{
	Q_OBJECT
	Q_INTERFACES( IModule )
public:
	bool	initialize( Workspace &ws );
	QString	name() const;
	QString	version() const;
	QStringList	depends() const;
};

#endif // GUIPLUGIN_H
