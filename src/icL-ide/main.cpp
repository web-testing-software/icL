#include "gateway.h"

#include <icL-look/export/look.h>

#include <iostream>

#include <QApplication>
#include <QDebug>
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
    QApplication app(argc, argv);
    QtWebEngine::initialize();

    // Now we are using a single engine
    // Thnaks to derM for his/her answer
    // https://stackoverflow.com/questions/52696330/how-to-create-some-independent-windows-in-qml/52699869
    QQmlApplicationEngine engine;

    QQmlContext * context = engine.rootContext();

    icL::ide::GateWay gateway;

    context->setContextProperty("gateway", &gateway);

    qmlRegisterSingletonType(
      {"qrc:/utils/MoveFlags.qml"}, "icL", 1, 0, "MoveFlags");

    engine.load("qrc:/windows/start-window.qml");
    engine.load("qrc:/main.qml");

    return QGuiApplication::exec();
    return 0;
}
