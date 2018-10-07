# toolkit - represent some usefull libs for QML

TARGET = icLtoolkitPlugin
TEMPLATE = lib
CONFIG += plugin

QT = core gui qml

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/lib.pri)

DESTDIR = $$ICL_ROOT/bin/$$BUILDTYPE/$$OS/icL/Toolkit

TARGET = $$qtLibraryTarget($$TARGET)
uri = icL.Toolkit

DISTFILES += \
    README.md \
    qmldir \
    toolkit.qmltypes \
    models/*.*uml


copy_qmldir.target = $$DESTDIR/qmldir
copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
copy_qmldir.commands = mkdir -p \"$$replace($$DESTDIR, /, $$QMAKE_DIR_SEP)\"; \
    $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
copy_qmltypes.target = $$DESTDIR/toolkit.qmltypes
copy_qmltypes.depends = $$_PRO_FILE_PWD_/toolkit.qmltypes
copy_qmltypes.commands = $(COPY_FILE) \"$$replace(copy_qmltypes.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmltypes.target, /, $$QMAKE_DIR_SEP)\"
QMAKE_EXTRA_TARGETS += copy_qmldir copy_qmltypes
PRE_TARGETDEPS += $$copy_qmldir.target $$copy_qmltypes.target

qmldir.files = qmldir toolkit.qmltypes
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += qmldir toolkit.qmltypes
}

HEADERS += \
    export/plugin.h \
    panels/browser.h \
    panels/code.h \
    panels/basepanels.h

SOURCES += \
    export/plugin.cpp \
    panels/browser.cpp \
    panels/code.cpp \
    panels/basepanels.cpp
