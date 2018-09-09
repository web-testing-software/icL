#-------------------------------------------------
#
# Project created by QtCreator 2018-07-16T20:03:00
#
#-------------------------------------------------

QT       -= gui

TARGET = -icl-context-operators
TEMPLATE = lib

ICL_ROOT = $$PWD/../../..

include($$ICL_ROOT/pri_files/lib.pri)

HEADERS += \
    assign/assign.h \
    logical/disjunction.h \
    logical/conjunction.h \
    logical/equivalence.h \
    logical/exclusiveor.h \
    comparative/equal.h \
    comparative/notequal.h \
    comparative/contains.h \
    comparative/containstemplate.h \
    comparative/lessthan.h \
    comparative/greaterthan.h \
    comparative/lessorequal.h \
    comparative/greaterorequal.h \
    arithmetic/plus.h \
    arithmetic/minus.h \
    arithmetic/multiply.h \
    arithmetic/devide.h \
    arithmetic/modulo.h \
    arithmetic/power.h \
    arithmetic/root.h \
    logical/inversion.h

SOURCES += \
    assign/assign.cpp \
    logical/disjunction.cpp \
    logical/conjunction.cpp \
    logical/equivalence.cpp \
    logical/exclusiveor.cpp \
    comparative/equal.cpp \
    comparative/notequal.cpp \
    comparative/contains.cpp \
    comparative/containstemplate.cpp \
    comparative/lessthan.cpp \
    comparative/greaterthan.cpp \
    comparative/lessorequal.cpp \
    comparative/greaterorequal.cpp \
    arithmetic/plus.cpp \
    arithmetic/minus.cpp \
    arithmetic/multiply.cpp \
    arithmetic/devide.cpp \
    arithmetic/modulo.cpp \
    arithmetic/power.cpp \
    arithmetic/root.cpp \
    logical/inversion.cpp
