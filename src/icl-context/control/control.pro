#-------------------------------------------------
#
# Project created by QtCreator 2018-05-13T13:41:00
#
#-------------------------------------------------

QT       -= gui

TARGET = -icl-context-control
TEMPLATE = lib

ICL_ROOT = $$PWD/../../..

include($$ICL_ROOT/pri_files/lib.pri)

HEADERS += \
    main/code.h \
    main/forany.h \
    control/main/control.h \
    control/main/else.h \
    control/main/if.h \
    control/catch/catch.h \
    control/catch/exists.h \
    control/catch/slot.h

SOURCES += \
    main/code.cpp \
    main/forany.cpp \
    control/main/control.cpp \
    control/main/else.cpp \
    control/main/if.cpp \
    control/catch/catch.cpp \
    control/catch/exists.cpp \
    control/catch/slot.cpp
