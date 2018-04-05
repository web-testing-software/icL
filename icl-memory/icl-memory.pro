TARGET = icl-memory
TEMPLATE = lib

QT = core
CONFIG -= app_bundle

CONFIG += staticlib
CONFIG += c++1z
QMAKE_CXXFLAGS += -std=c++1z

INCLUDEPATH += ../


unix {
	target.path = /usr/lib
	INSTALLS += target
}

HEADERS += \
	state/datastate.h \
    state/memorystate.h \
    state/stackstate.h \
    state/datacontainer.h \
    structures/webelement.h

SOURCES += \
	state/datastate.cpp \
    state/memorystate.cpp \
    state/stackstate.cpp \
    state/datacontainer.cpp \
    structures/webelement.cpp

DISTFILES += \
    models/engine.plantuml \
    models/uml_style.iuml \
    models/engine.plantuml \
    models/uml_style.iuml \
    models/engine.plantuml \
    models/uml_style.iuml \
    models/engine.plantuml \
    models/uml_style.iuml
