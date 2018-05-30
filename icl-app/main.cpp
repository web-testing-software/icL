#include "backend/helper.h"
//#include "backend/serverhighlevel.h"
//#include "backend/steptypehighlevel.h"
//#include "backend/vmstackhighlevel.h"
#include "data_management/database.h"
#include "data_management/dialdescription.h"

#include <icl-memory/structures/steptype.h>
#include <icl-vm/server.h>
#include <icl-vm/vmstack.h>

#include <QApplication>
#include <QObject>
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
	  "icL.DB", 1, 0, "DialDescription");

	qmlRegisterType<icL::Server>("icL.VM", 1, 0, "Server");
	qmlRegisterType<icL::VMStack>("icL.VM", 1, 0, "VMStack");

	qmlRegisterUncreatableMetaObject(
	  icL::memory::StepType::staticMetaObject,  // static meta object
	  "icL.Enums",    // import statement (can be any string)
	  1, 0,        // major and minor version of the import
	  "StepType",  // name in QML (does not have to match C++ name)
	  "Error: This is a enum continer."  // error in case someone tries to
										 // create a MyNamespace object
	);

	QQmlApplicationEngine engine;
	QQmlContext *         context = engine.rootContext();

	context->setContextProperty("helper", &helper);
	context->setContextProperty("database", &database);

	engine.load(QUrl("qrc:/driver.qml"));
	return QGuiApplication::exec();
}
