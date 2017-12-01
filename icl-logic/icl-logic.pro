TARGET = icl-logic
TEMPLATE = lib

CONFIG += staticlib C++11

INCLUDEPATH += ../icl-memory

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
    rich/stringliststringblock.h \
    main/crossblock.h \
    main/falseblock.h \
    main/logicblock.h \
    main/richblock.h \
    main/trueblock.h

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
    rich/stringliststringblock.cpp \
    main/crossblock.cpp \
    main/falseblock.cpp \
    main/logicblock.cpp \
    main/richblock.cpp \
    main/trueblock.cpp

DISTFILES += \
	models/logic.plantuml
