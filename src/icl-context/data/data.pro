#-------------------------------------------------
#
# Project created by QtCreator 2018-05-13T13:41:00
#
#-------------------------------------------------

QT       -= gui

TARGET = -icl-context-data
TEMPLATE = lib

ICL_ROOT = $$PWD/../../..
DESTDIR = $$ICL_ROOT/bin/lib

CONFIG += c++17 no_include_pwd
QMAKE_CXXFLAGS += -std=c++1z

INCLUDEPATH += ../..

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
    main/alternative.h \
    main/assign.h \
    main/data.h \
    main/function.h \
    main/method.h \
    main/parameter.h \
    main/property.h \
    js/js.h \
    js/get.h \
    js/set.h \
    js/file.h \
    js/crossfire.h \
    js/var.h \
    js/value.h

SOURCES += \
    main/alternative.cpp \
    main/assign.cpp \
    main/data.cpp \
    main/function.cpp \
    main/method.cpp \
    main/parameter.cpp \
    main/property.cpp \
    js/js.cpp \
    js/get.cpp \
    js/set.cpp \
    js/file.cpp \
    js/crossfire.cpp \
    js/var.cpp \
    js/value.cpp
