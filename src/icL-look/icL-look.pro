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
    base/effectadv.h

SOURCES += \
    base/text.cpp \
    base/link.cpp \
    base/linkadv.cpp \
    base/effect.cpp \
    base/effectadv.cpp

