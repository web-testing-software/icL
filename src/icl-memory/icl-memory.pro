TARGET = -icl-memory
TEMPLATE = lib

QT = core
CONFIG -= app_bundle

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/lib.pri)

HEADERS += \
	state/datastate.h \
    state/memorystate.h \
    state/stackstate.h \
    structures/functioncontainer.h \
    structures/type.h \
    state/memory.h \
    structures/return.h \
    structures/exception.h \
    interlevel/interlevel.h \
    interlevel/interfaces.h \
    interlevel/node.h \
    structures/steptype.h \
    structures/set.h \
    structures/element.h

SOURCES += \
	state/datastate.cpp \
    state/memorystate.cpp \
    state/stackstate.cpp \
    structures/functioncontainer.cpp \
    state/memory.cpp \
    structures/return.cpp \
    structures/exception.cpp \
    structures/type.cpp \
    structures/element.cpp

DISTFILES += \
    models/uml_style.iuml \
    models/dataState_checkType.plantuml \
    models/dataState_getType.plantuml \
    models/stackStateIt_clear.plantuml \
    models/stackStateIt_closeStack.plantuml \
    models/stackStateIt_getContainer.plantuml \
    models/stackStateIt_openNewStack.plantuml \
    models/class_diagram.plantuml
