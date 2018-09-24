# ide - integrated development environment

QT       += core widgets gui qml webengine sql

TARGET = icL-ide
TEMPLATE = app

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/app.pri)


SOURCES += \
    main.cpp

RESOURCES += \
    qml/qml.qrc \
    qml/bottomside/qml.qrc \
    qml/centralside/qml.qrc \
    qml/leftpanel/qml.qrc \
    qml/sessions/qml.qrc \
    qml/navigationbar/qml.qrc \
    qml/startwindow/qmldow.qrc \
    qml/static/qml.qrc


DISTFILES += \
    README.md \
    models/*.*uml
