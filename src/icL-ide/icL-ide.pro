# ide - integrated development environment

QT       += core widgets gui qml webengine sql

TARGET = icL-ide
TEMPLATE = app

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/app.pri)

DEFINES += icL_root=\"$$ICL_ROOT\"

QML_IMPORT_PATH += $$DESTDIR

SOURCES += \
    main.cpp \
    gateway.cpp

RESOURCES += \
    qml/qml.qrc \
    qml/bottomside.qrc \
    qml/centralside.qrc \
    qml/leftpanel.qrc \
    qml/sessions.qrc \
    qml/navigationbar.qrc \
    qml/static.qrc \
    qml/startwindow.qrc \
    qml/themes.qrc \
    qml/themes-images.qrc \
    qml/ui.qrc \
    qml/utils.qrc


DISTFILES += \
    README.md \
    models/*.*uml

HEADERS += \
    gateway.h
