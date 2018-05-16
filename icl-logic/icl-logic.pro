TARGET = icl-logic
TEMPLATE = lib

QT = core
CONFIG -= app_bundle

CONFIG += staticlib
CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
DEFINES *= QT_USE_QSTRINGBUILDER

INCLUDEPATH += ../ \
    ../icl-memory

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
    main/crossblock.h \
    main/logicblock.h \
    main/richblock.h \
    cross/eqblock.h \
    rich/listblock.h

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
    main/crossblock.cpp \
    main/logicblock.cpp \
    main/richblock.cpp \
    cross/eqblock.cpp \
    rich/listblock.cpp

DISTFILES += \
    models/uml_style.iuml \
    models/crossBlock_step.plantuml \
    models/first_anonim_function.plantuml \
    models/richBlock_step.plantuml \
    models/socond_anonim_function.plantuml \
    models/uml_style.iuml \
    models/logicBlock_castNow.plantuml \
    models/logicBlock_needCast.plantuml \
    models/richBlack_castNow.plantuml \
    models/richBlock_needCast.plantuml \
    models/class_diagram.plantuml
