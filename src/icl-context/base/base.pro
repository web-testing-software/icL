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
    object/double.h \
    object/element.h \
    object/int.h \
    object/list.h \
    object/string.h \
    object/void.h \
    object/set.h \
    object/setobject.h \
    object/bool.h \
    object/value.h

SOURCES += \
    context.cpp \
    object/double.cpp \
    object/element.cpp \
    object/int.cpp \
    object/list.cpp \
    object/string.cpp \
    object/void.cpp \
    object/set.cpp \
    object/setobject.cpp \
    object/bool.cpp \
    object/value.cpp
