#-------------------------------------------------
#
# Project created by QtCreator 2018-05-13T13:41:00
#
#-------------------------------------------------

QT       -= gui

TARGET = -icl-context-complex
TEMPLATE = lib

ICL_ROOT = $$PWD/../../..

include($$ICL_ROOT/pri_files/lib.pri)

HEADERS += \
    complex.h \
    define.h \
    dom.h \
    log.h \
    tab.h

SOURCES += \
    complex.cpp \
    define.cpp \
    dom.cpp \
    log.cpp \
    tab.cpp
