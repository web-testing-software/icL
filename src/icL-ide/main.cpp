#include "gateway.h"

#include <iostream>

#include <QApplication>
#include <QDebug>
#include <QObject>
#include <QOpenGLContext>
#include <QQmlEngine>
#include <QSurface>
#include <QtWebEngine>

#include <icL-look/export/look.h>


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
	QApplication app(argc, argv);
	QtWebEngine::initialize();

	QQmlApplicationEngine startWindow;
	QQmlApplicationEngine sessionWindow;

	QQmlContext * startContext   = startWindow.rootContext();
	QQmlContext * sessionContext = sessionWindow.rootContext();

	icL::ide::GateWay gateway;

	startContext->setContextProperty("gateway", &gateway);
	sessionContext->setContextProperty("gateway", &gateway);

	startWindow.load("qrc:/windows/start-window.qml");
	sessionWindow.load("qrc:/main.qml");

	QObject::connect(
	  &startWindow, &QQmlApplicationEngine::quit, &app,
	  &QApplication::closeAllWindows);

	return QGuiApplication::exec();
	return 0;
}
