#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QObject>
#include <QScopedPointer>
#include "corelib_global.h"

class Workspace;
class QStringList;

class CORELIB_EXPORT ModuleLoader : public QObject
{
	Q_OBJECT
	Q_DISABLE_COPY( ModuleLoader );
public:
    ModuleLoader();
    virtual ~ModuleLoader();

	virtual void		initAll( Workspace &ws );

	QStringList			initializedModules() const;
	
private:
	class Priv;
	QScopedPointer<Priv>	m_d;
};

#endif // PLUGINMANAGER_H
