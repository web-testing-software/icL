#-------------------------------------------------
#
# Project created by QtCreator 2018-05-13T13:41:00
#
#-------------------------------------------------

QT       -= gui

TARGET = -icl-context-control
TEMPLATE = lib

ICL_ROOT = $$PWD/../..
DESTDIR = $$ICL_ROOT/bin/lib

CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++1z

INCLUDEPATH += ../..
INCLUDEPATH -= .

icl-static {
    LIBS += $$ICL_ROOT/bin/lib/lib-static-icl-memory.a
    LIBS += $$ICL_ROOT/bin/lib/lib-static-icl-logic.a
    LIBS += $$ICL_ROOT/bin/lib/lib-static-icl-context-base.a
}
else {
    LIBS += $$ICL_ROOT/bin/lib/lib-icl-memory.so
    LIBS += $$ICL_ROOT/bin/lib/lib-icl-logic.so
    LIBS += $$ICL_ROOT/bin/lib/lib-icl-context-base.so
}

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
