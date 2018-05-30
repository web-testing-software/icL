#include "backend/helper.h"
#include "backend/serverhighlevel.h"
#include "backend/steptypehighlevel.h"
#include "backend/vmstackhighlevel.h"
#include "data_management/database.h"
#include "data_management/dialdescription.h"

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
	  "icL.DB", 1, 0, "DialDescription");

	//	qRegisterMetaType<icL::app::StepTypeHighLevel::Value>("StepType");
	qmlRegisterUncreatableType<icL::app::StepTypeHighLevel>(
	  "icL.VM", 1, 0, "StepType", "Step by step run argument");

//	icL::app::ServerHighLevel server;
	//	icL::memory::StepType step;

	qmlRegisterType<icL::app::ServerHighLevel>("icL.VM", 1, 0, "Server");
	qmlRegisterType<icL::app::VMStackHighLevel>("icL.VM", 1, 0, "VMStack");



	QQmlApplicationEngine engine;
	QQmlContext *         context = engine.rootContext();

	context->setContextProperty("helper", &helper);
	context->setContextProperty("database", &database);

	engine.load(QUrl("qrc:/driver.qml"));
	return QGuiApplication::exec();
}
