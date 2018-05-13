#-------------------------------------------------
#
# Project created by QtCreator 2018-05-13T13:41:00
#
#-------------------------------------------------

QT       -= gui

TARGET = context-data
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

INCLUDEPATH += \
    .. \
    ../.. \
    ../context-base \
    ../context-control

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES *= QT_USE_QSTRINGBUILDER

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    alternative.h \
    assign.h \
    data.h \
    function.h \
    method.h \
    parameter.h \
    property.h

SOURCES += \
    alternative.cpp \
    assign.cpp \
    data.cpp \
    function.cpp \
    method.cpp \
    parameter.cpp \
    property.cpp
