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
    structures/webelement.h \
    structures/functioncontainer.h \
    structures/type.h \
    state/memory.h

SOURCES += \
	state/datastate.cpp \
    state/memorystate.cpp \
    state/stackstate.cpp \
    structures/webelement.cpp \
    structures/functioncontainer.cpp \
    state/memory.cpp

DISTFILES += \
    models/uml_style.iuml \
    models/dataState_checkType.plantuml \
    models/dataState_getType.plantuml \
    models/stackStateIt_clear.plantuml \
    models/stackStateIt_closeStack.plantuml \
    models/stackStateIt_getContainer.plantuml \
    models/stackStateIt_openNewStack.plantuml \
    models/class_diagram.plantuml
