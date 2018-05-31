#-------------------------------------------------
#
# Project created by QtCreator 2018-05-13T13:41:00
#
#-------------------------------------------------

QT       -= gui

TARGET = -icl-context-base
TEMPLATE = lib

ICL_ROOT = $$PWD/../..
DESTDIR = $$ICL_ROOT/bin/lib

CONFIG += c++17 unversioned_libname
QMAKE_CXXFLAGS += -std=c++1z

INCLUDEPATH += ../..
INCLUDEPATH -= .

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
# disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    context.h \
    object/boolean.h \
    object/double.h \
    object/element.h \
    object/int.h \
    object/list.h \
    object/object.h \
    object/string.h \
    object/void.h

SOURCES += \
    context.cpp \
    object/boolean.cpp \
    object/double.cpp \
    object/element.cpp \
    object/int.cpp \
    object/list.cpp \
    object/object.cpp \
    object/string.cpp \
    object/void.cpp
