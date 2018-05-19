TARGET = icl-logic
TEMPLATE = lib

QT = core
CONFIG -= app_bundle

CONFIG += staticlib
CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

INCLUDEPATH += ../ \
    ../icl-memory

unix {
	target.path = /usr/lib
	INSTALLS += target
}

HEADERS += \
    rich/booleanblock.h \
    rich/doubleblock.h \
    rich/intblock.h \
    rich/singleblock.h \
    rich/stringblock.h \
    rich/listblock.h \
    cross/and.h \
    cross/eq.h \
    cross/not.h \
    cross/or.h \
    cross/xor.h \
    main/cross.h \
    main/logic.h \
    main/rich.h

SOURCES += \
    cross/and.cpp \
    cross/eq.cpp \
    cross/not.cpp \
    cross/or.cpp \
    cross/xor.cpp \
    main/cross.cpp \
    main/logic.cpp \
    main/rich.cpp \
    rich/boolean.cpp \
    rich/double.cpp \
    rich/int.cpp \
    rich/list.cpp \
    rich/single.cpp \
    rich/string.cpp

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
