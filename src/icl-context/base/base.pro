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
    value/base/bool.h \
    value/base/double.h \
    value/base/int.h \
    value/base/list.h \
    value/base/string.h \
    value/base/value.h \
    value/base/void.h \
    value/complex/element.h \
    value/complex/set.h \
    value/complex/setobject.h \
    value/complex/regexp.h \
    value/complex/object.h \
    value/complex/database.h \
    value/complex/requestresult.h

SOURCES += \
    context.cpp \
    value/base/bool.cpp \
    value/base/double.cpp \
    value/base/int.cpp \
    value/base/list.cpp \
    value/base/string.cpp \
    value/base/value.cpp \
    value/base/void.cpp \
    value/complex/element.cpp \
    value/complex/set.cpp \
    value/complex/setobject.cpp \
    value/complex/regexp.cpp \
    value/complex/object.cpp \
    value/complex/database.cpp \
    value/complex/requestresult.cpp
