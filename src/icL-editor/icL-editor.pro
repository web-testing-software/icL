# editor - code editor pro

TARGET = -icL-editor
TEMPLATE = lib

QT = core gui
CONFIG -= app_bundle

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/lib.pri)


DISTFILES += \
    README.md

HEADERS += \
    look/chars.h

SOURCES += \
    look/chars.cpp


