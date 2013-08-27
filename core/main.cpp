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
	
	// Выводим список сервисов
	ws.dump();
	
	// Получаем указатель на логгер по его интерфейсу
	ILogger *l = ws.service<ILogger>();
	Q_ASSERT( l );
	// Используем сервис логирования
	l->log( "Execution..." );
	
	return app.exec();
}
