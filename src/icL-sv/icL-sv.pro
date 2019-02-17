# sv - Separated Values

TARGET = -icL-sv
TEMPLATE = lib

QT = core
CONFIG -= app_bundle

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/lib.pri)


DISTFILES += \
    README.md

HEADERS += \
    class.h

SOURCES += \
    class.cpp

