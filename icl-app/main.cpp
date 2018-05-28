#include "backend/helper.h"
#include "data_management/database.h"
#include "data_management/dialdescription.h"

#include <icl-vm/server.h>

#include <QApplication>
#include <QOpenGLContext>
#include <QQmlEngine>
#include <QSurface>
#include <QtWebEngine>

int main(int argc, char * argv[]) {
	QGuiApplication    a(argc, argv);
	icL::app::Helper   helper;
	icL::app::DataBase database;

	QtWebEngine::initialize();

	qmlRegisterType<icL::app::DialDescription>(
	  "ICLightning.Database", 1, 0, "DialDescription");

	qmlRegisterType<icL::Server>("icL.VM", 1, 0, "Server");

	QQmlApplicationEngine engine;
	QQmlContext *         context = engine.rootContext();

	context->setContextProperty("helper", &helper);
	context->setContextProperty("database", &database);

	engine.load(QUrl("qrc:/driver.qml"));
	return QGuiApplication::exec();
}
