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

/**
 * @file main.cpp - decalar window object and QML meta types.
 * @mainpage Main page of icL Documentation
 * @author Lelițac Vasile - lixcode
 * icL (intra-cloud Lignning) is a new, modern and powerfull web testing tool,
 * the main goal of the project is to speed up the testing process. icL
 * has a integrated command processor and special scripting language, the
 * language is focused to testers with coding skills, the icL lang is very
 * simple. Some very complex command is icL are very simples. It support
 * data types as strings, lists, sets. The filosofy of icL is descripted in
 * the standard for language. This project is in active development and is not
 * ready to release. The icl libs are just for internal use, but they are
 * documentated for developers, which want to join the icL developement.
 * You are wellcome!
 */

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
	  "icL.Enums",  // import statement (can be any string)
	  1, 0,         // major and minor version of the import
	  "StepType",   // name in QML (does not have to match C++ name)
	  "Error: This is a enum continer."  // error in case someone tries to
										 // create a StepType object
	);

	QQmlApplicationEngine engine;
	QQmlContext *         context = engine.rootContext();

	context->setContextProperty("helper", &helper);
	context->setContextProperty("database", &database);

	engine.load(QUrl("qrc:/driver.qml"));
	return QGuiApplication::exec();
}
