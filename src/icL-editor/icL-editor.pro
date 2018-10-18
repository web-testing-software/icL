# editor - code editor pro

TARGET = icLeditorPlugin
TEMPLATE = lib
CONFIG += plugin

QT = core gui quick

ICL_ROOT = $$PWD/../..

uri = icL.Editor
QML_TYPES = editor.qmltypes
include($$ICL_ROOT/pri_files/qmlplugin.pri)

DISTFILES += \
    README.md \
    qmldir \
    editor.qmltypes \
    models/*.*uml

HEADERS += \
    export/plugin.h \
    private/line.h \
    private/fragment.h \
    private/cursor.h \
    private/selection.h \
    self/logic.h \
    self/drawing.h

SOURCES += \
    export/plugin.cpp \
    private/line.cpp \
    private/fragment.cpp \
    private/cursor.cpp \
    private/selection.cpp \
    self/logic.cpp \
    self/drawing.cpp
