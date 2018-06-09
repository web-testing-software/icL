#-------------------------------------------------
#
# Project created by QtCreator 2018-05-13T13:41:00
#
#-------------------------------------------------

QT       -= gui

TARGET = -icl-context-base
TEMPLATE = lib

ICL_ROOT = $$PWD/../../..

include($$ICL_ROOT/pri_files/lib.pri)

HEADERS += \
    context.h \
    object/boolean.h \
    object/double.h \
    object/element.h \
    object/int.h \
    object/list.h \
    object/object.h \
    object/string.h \
    object/void.h \
    object/set.h

SOURCES += \
    context.cpp \
    object/boolean.cpp \
    object/double.cpp \
    object/element.cpp \
    object/int.cpp \
    object/list.cpp \
    object/object.cpp \
    object/string.cpp \
    object/void.cpp \
    object/set.cpp
