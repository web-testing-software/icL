# editor - code editor pro

TARGET = icLeditorPlugin
TEMPLATE = lib
CONFIG += plugin

QT = core gui quick

ICL_ROOT = $$PWD/../..

uri = icL.Editor
QML_TYPES = editor.qmltypes
include($$ICL_ROOT/pri_files/qmlplugin.pri)

copy_editor_qml.target = $$DESTDIR/Editor.qml
copy_editor_qml.depends = $$_PRO_FILE_PWD_/Editor.qml
copy_editor_qml.commands = $(COPY_FILE) \"$$replace(copy_editor_qml.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_editor_qml.target, /, $$QMAKE_DIR_SEP)\"

QMAKE_EXTRA_TARGETS += copy_editor_qml
PRE_TARGETDEPS += $$copy_editor_qml.target


DISTFILES += \
    README.md \
    qmldir \
    editor.qmltypes \
    models/*.*uml \
    Editor.qml

HEADERS += \
    export/plugin.h \
    private/line.h \
    fragment/fragment.h \
    private/cursor.h \
    private/selection.h \
    self/logic.h \
    self/drawing.h \
    self/history.h \
    self/keyboard.h \
    self/mouse.h \
    private/styleproxy.h \
    fragment/word.h \
    fragment/string.h \
    fragment/bracket.h \
    private/fixer.h \
    self/linenumbers.h \
    private/alpha.h \
    self/opacitymask.h \
    self/editorinternal.h \
    self/cursorsarea.h \
    self/scroll.h \
    history/revision.h \
    history/externalchanges.h \
    history/changesentity.h

SOURCES += \
    export/plugin.cpp \
    private/line.cpp \
    fragment/fragment.cpp \
    private/cursor.cpp \
    private/selection.cpp \
    self/logic.cpp \
    self/drawing.cpp \
    self/history.cpp \
    self/keyboard.cpp \
    self/mouse.cpp \
    private/styleproxy.cpp \
    fragment/word.cpp \
    fragment/string.cpp \
    fragment/bracket.cpp \
    private/fixer.cpp \
    self/linenumbers.cpp \
    private/alpha.cpp \
    self/opacitymask.cpp \
    self/editorinternal.cpp \
    self/cursorsarea.cpp \
    self/scroll.cpp \
    history/externalchanges.cpp \
    history/changesentity.cpp
