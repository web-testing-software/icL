TARGET = icl-logic
TEMPLATE = lib

QT = core
CONFIG -= app_bundle

CONFIG += staticlib
CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

INCLUDEPATH += ../

unix {
	target.path = /usr/lib
	INSTALLS += target
}

HEADERS += \
    cross/andblock.h \
    cross/notblock.h \
    cross/orblock.h \
	cross/xorblock.h \
    rich/booleanblock.h \
    rich/doubleblock.h \
    rich/intblock.h \
    rich/singleblock.h \
    rich/stringblock.h \
    rich/stringlistblock.h \
    main/crossblock.h \
    main/logicblock.h \
    main/richblock.h \
    cross/eqblock.h

SOURCES += \
    cross/andblock.cpp \
    cross/notblock.cpp \
    cross/orblock.cpp \
	cross/xorblock.cpp \
    rich/booleanblock.cpp \
    rich/doubleblock.cpp \
    rich/intblock.cpp \
    rich/singleblock.cpp \
    rich/stringblock.cpp \
    rich/stringlistblock.cpp \
    main/crossblock.cpp \
    main/logicblock.cpp \
    main/richblock.cpp \
    cross/eqblock.cpp

DISTFILES += \
	models/logic.plantuml \
    models/uml_style.iuml
