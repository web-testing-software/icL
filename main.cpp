#include "webbrowser.h"
#include "backend/helper.h"
#include "data_management/database.h"
#include "data_management/dialdescription.h"

#include <QApplication>
#include <QOpenGLContext>
#include <QSurface>
#include <QQmlEngine>
#include <QtWebEngine>

int main (int argc, char *argv []) {
	QGuiApplication a (argc, argv);
	Helper helper;
	DataBase database;

	QtWebEngine::initialize ();

	qmlRegisterType<DialDescription>("ICLightning.Database", 1, 0, "DialDescription");

	QQmlApplicationEngine engine;
	QQmlContext* context = engine.rootContext ();

	context->setContextProperty ("helper", &helper);
	context->setContextProperty ("database", &database);

	engine.load (QUrl("qrc:/drive.qml"));
	return a.exec ();
}
