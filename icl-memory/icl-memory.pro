 
TARGET = icl-memory
TEMPLATE = lib

CONFIG += staticlib C++11


unix {
	target.path = /usr/lib
	INSTALLS += target
}

HEADERS += \
	state/datastate.h \
    state/memorystate.h \
    state/stackstate.h \
    state/virtualmachine.h \
    state/datacontainer.h \
    structures/webelement.h

SOURCES += \
	state/datastate.cpp \
    state/memorystate.cpp \
    state/stackstate.cpp \
    state/virtualmachine.cpp \
    state/datacontainer.cpp \
    structures/webelement.cpp

DISTFILES += \
    models/engine.plantuml \
    models/uml_style.iuml
