# look - personalize look of programs

TARGET = icLlookPlugin
TEMPLATE = lib
CONFIG += plugin

QT = core gui qml

ICL_ROOT = $$PWD/../..

uri = icL.Look
QML_TYPES = look.qmltypes
include($$ICL_ROOT/pri_files/qmlplugin.pri)

DISTFILES += \
    README.md \
    qmldir \
    look.qmltypes \
    models/*.*uml

HEADERS += \
    base/link.h \
    base/linkadv.h \
    base/effect.h \
    base/effectadv.h \
    start/input.h \
    start/listitem.h \
    start/side.h \
    start/startwindow.h \
    session/tree.h \
    session/leftside.h \
    session/topbar.h \
    session/floating.h \
    session/issue.h \
    session/centralside.h \
    session/sessionwindow.h \
    editor/highlight.h \
    editor/line.h \
    editor/charformatbase.h \
    editor/charformat.h \
    editor/editor.h \
    export/look.h \
    export/plugin.h \
    base/baselook.h \
    base/textlook.h \
    session/static.h \
    export/chars.h \
    editor/editorstyle.h \
    editor/scrollbar.h \
    editor/change.h

SOURCES += \
    base/link.cpp \
    base/linkadv.cpp \
    base/effect.cpp \
    base/effectadv.cpp \
    start/input.cpp \
    start/listitem.cpp \
    start/side.cpp \
    start/startwindow.cpp \
    session/tree.cpp \
    session/leftside.cpp \
    session/topbar.cpp \
    session/floating.cpp \
    session/issue.cpp \
    session/centralside.cpp \
    session/sessionwindow.cpp \
    editor/highlight.cpp \
    editor/line.cpp \
    editor/charformatbase.cpp \
    editor/charformat.cpp \
    editor/editor.cpp \
    export/look.cpp \
    export/plugin.cpp \
    base/baselook.cpp \
    base/textlook.cpp \
    session/static.cpp \
    export/chars.cpp \
    editor/editorstyle.cpp \
    editor/scrollbar.cpp \
    editor/change.cpp
