# look - personalize look of programs

TARGET = icLlookPlugin
TEMPLATE = lib
CONFIG += plugin

QT = core gui qml

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/lib.pri)

DESTDIR = $$ICL_ROOT/bin/$$BUILDTYPE/$$OS/icL/Look

TARGET = $$qtLibraryTarget($$TARGET)
uri = icL.Look

DISTFILES += \
    README.md \
    qmldir \
    look.qmltypes

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
    export/chars.h

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
    export/chars.cpp

copy_qmldir.target = $$DESTDIR/qmldir
copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
copy_qmldir.commands = mkdir -p \"$$replace($$DESTDIR, /, $$QMAKE_DIR_SEP)\"; \
    $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
copy_qmltypes.target = $$DESTDIR/look.qmltypes
copy_qmltypes.depends = $$_PRO_FILE_PWD_/look.qmltypes
copy_qmltypes.commands = $(COPY_FILE) \"$$replace(copy_qmltypes.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmltypes.target, /, $$QMAKE_DIR_SEP)\"
QMAKE_EXTRA_TARGETS += copy_qmldir copy_qmltypes
PRE_TARGETDEPS += $$copy_qmldir.target $$copy_qmltypes.target

qmldir.files = qmldir look.qmltypes
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += qmldir look.qmltypes
}
