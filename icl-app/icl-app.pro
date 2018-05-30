#-------------------------------------------------
#
# Project started 2016-12-03
# Project alived 2017-07-28
# Project created by QtCreator 2017-08-16T08:13:21
#
#-------------------------------------------------

QT       += core gui widgets quickwidgets webengine sql

TARGET = icL
TEMPLATE = app

ICL_ROOT = $$PWD/..
DESTDIR = $$ICL_ROOT/bin

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
# disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

INCLUDEPATH += ..

LIBS += -L$$ICL_ROOT/bin/lib
LIBS += -l-icl-memory
LIBS += -l-icl-logic
LIBS += -l-icl-context-base
LIBS += -l-icl-context-complex
LIBS += -l-icl-context-control
LIBS += -l-icl-context-data
LIBS += -l-icl-inter
LIBS += -l-icl-vm

SOURCES += \
        main.cpp \
	backend/helper.cpp \
        data_management/database.cpp \
	data_management/dialdescription.cpp \
    backend/steptypehighlevel.cpp \
    backend/serverhighlevel.cpp \
    backend/vmstackhighlevel.cpp

HEADERS += \
	backend/helper.h \
        data_management/database.h \
	data_management/dialdescription.h \
    backend/steptypehighlevel.h \
    backend/serverhighlevel.h \
    backend/vmstackhighlevel.h

RESOURCES += \
    qml/main.qrc \
    sql/sql.qrc \
    images/images.qrc

CONFIG(debug, debug|release) {
    OBJECTS_DIR = debug/objs
    MOC_DIR = debug/moc
    RCC_DIR = debug/rcc

	DEFINES += ICL_ADD_TEST_DB_DATA
}
else {
    OBJECTS_DIR = release/objs
    MOC_DIR = release/moc
	RCC_DIR = release/rcc
}

CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

DISTFILES += \
    uml2png.sh \
    uml2svg.sh \
    models/uml_style.iuml \
    models/use_case.plantuml \
    models/modules.plantuml \
    _clang-format

