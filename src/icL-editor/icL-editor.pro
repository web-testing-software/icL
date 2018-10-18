# editor - code editor pro

TARGET = icLeditorPlugin
TEMPLATE = lib
CONFIG += plugin

QT = core gui quick

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/lib.pri)

DESTDIR = $$ICL_ROOT/bin/$$BUILDTYPE/$$OS/icL/Editor

TARGET = $$qtLibraryTarget($$TARGET)
uri = icL.Editor


DISTFILES += \
    README.md \
    qmldir \
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

copy_qmldir.target = $$DESTDIR/qmldir
copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
copy_qmldir.commands = mkdir -p \"$$replace($$DESTDIR, /, $$QMAKE_DIR_SEP)\"; \
    $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"

QMAKE_EXTRA_TARGETS += copy_qmldir
PRE_TARGETDEPS += $$copy_qmldir.target

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += qmldir
}
