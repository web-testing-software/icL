# toolkit - represent some usefull libs for QML

TARGET = icLtoolkitPlugin
TEMPLATE = lib
CONFIG += plugin

QT = core gui qml

ICL_ROOT = $$PWD/../..

uri = icL.Toolkit
QML_TYPES = toolkit.qmltypes
include($$ICL_ROOT/pri_files/qmlplugin.pri)

DISTFILES += \
    README.md \
    qmldir \
    toolkit.qmltypes \
    models/*.*uml

HEADERS += \
    export/plugin.h \
    panels/browser.h \
    panels/code.h \
    panels/basepanels.h \
    panels/debug.h \
    export/panels.h \
    utils/mousetracker.h \
    session/session.h \
    tree/item.h \
    tree/folder.h \
    tree/finaly.h \
    session/project.h \
    session/libs.h \
    session/resources.h \
    session/script.h \
    session/lib.h \
    session/resource.h \
    utils/remotecall.h

SOURCES += \
    export/plugin.cpp \
    panels/browser.cpp \
    panels/code.cpp \
    panels/basepanels.cpp \
    panels/debug.cpp \
    export/panels.cpp \
    utils/mousetracker.cpp \
    session/session.cpp \
    tree/item.cpp \
    tree/folder.cpp \
    tree/finaly.cpp \
    session/project.cpp \
    session/libs.cpp \
    session/resources.cpp \
    session/script.cpp \
    session/lib.cpp \
    session/resource.cpp \
    utils/remotecall.cpp
