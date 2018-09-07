TARGET = -icl-dsv
TEMPLATE = lib

QT = core
CONFIG -= app_bundle

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/lib.pri)

HEADERS += \
    tsv.h

SOURCES += \
    tsv.cpp

