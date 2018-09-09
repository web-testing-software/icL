#-------------------------------------------------
#
# Project created by QtCreator 2018-05-13T13:41:00
#
#-------------------------------------------------

QT       -= gui

TARGET = -icl-context-data
TEMPLATE = lib

ICL_ROOT = $$PWD/../../..

include($$ICL_ROOT/pri_files/lib.pri)

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
