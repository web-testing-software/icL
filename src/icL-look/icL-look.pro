# look - personalize look of programs

TARGET = -icl-look
TEMPLATE = lib

QT = core gui
CONFIG -= app_bundle

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/lib.pri)


DISTFILES += \
    README.md

HEADERS += \
    base/text.h \
    base/link.h \
    base/linkadv.h \
    base/effect.h \
    base/effectadv.h \
    start/input.h \
    start/listitem.h \
    start/side.h \
    start/startwindow.h \
    session/tree.h \
    session/leftside.h \
    session/topbar.h \
    session/floating.h \
    session/issue.h

SOURCES += \
    base/text.cpp \
    base/link.cpp \
    base/linkadv.cpp \
    base/effect.cpp \
    base/effectadv.cpp \
    start/input.cpp \
    start/listitem.cpp \
    start/side.cpp \
    start/startwindow.cpp \
    session/tree.cpp \
    session/leftside.cpp \
    session/topbar.cpp \
    session/floating.cpp \
    session/issue.cpp

