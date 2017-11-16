#include "webbrowser.h"
#include "backend/helper.h"

#include <QApplication>
#include <QOpenGLContext>
#include <QSurface>
#include <QQmlEngine>
#include <QtWebEngine>

//#include "backend/virtualmachine/language/control/singleshot.h"

int main (int argc, char *argv []) {
//	QApplication::setAttribute (Qt::AA_EnableHighDpiScaling);s

//	QGuiApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
	QGuiApplication a (argc, argv);
	Helper helper;

	QtWebEngine::initialize ();

	QQmlApplicationEngine engine;

	QQmlContext* context = engine.rootContext ();
	context->setContextProperty ("helper", &helper);

	engine.load (QUrl("qrc:/driver.qml"));
	return a.exec ();
}
