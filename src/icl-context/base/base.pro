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
    value/double.h \
    value/element.h \
    value/int.h \
    value/list.h \
    value/string.h \
    value/void.h \
    value/set.h \
    value/setobject.h \
    value/bool.h \
    value/value.h

SOURCES += \
    context.cpp \
    value/double.cpp \
    value/element.cpp \
    value/int.cpp \
    value/list.cpp \
    value/string.cpp \
    value/void.cpp \
    value/set.cpp \
    value/setobject.cpp \
    value/bool.cpp \
    value/value.cpp
