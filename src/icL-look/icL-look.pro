# look - personalize look of programs

TARGET = -icl-look
TEMPLATE = lib

QT = core
CONFIG -= app_bundle

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/lib.pri)


DISTFILES += \
    README.md

