#include <QApplication>
#include "moduleloader.h"
#include "workspace.h"
#include "ilogger.h"
#include "imainwindow.h"
#include <QStringList>
#include <QDebug>

int main( int argc, char *argv[] )
{
	QApplication app( argc, argv );
	
	// Создаем рабочее пространство
	Workspace ws;
	
	// Загружаем модули
	// При загрузке модули могут регистрировать в рабочем пространстве свои сервисы
	ModuleLoader loader;
	loader.initAll( ws );

	qDebug() << "Initialized modules:" << loader.initializedModules();
	qDebug() << "Registration services: " << ws.services();
	
	// Получаем указатель на логгер по его интерфейсу
	ILogger *l = ws.service<ILogger>();
	if( l )
		l->log( "Execution..." );
	
	// Если сервис главного окна зарегестрирован, то запускаем очередь сообщений
	return ( ws.service<IMainWindow>() )? app.exec() : 0;
}
