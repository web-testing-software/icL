# editor - code editor pro

TARGET = -icl-editor
TEMPLATE = lib

QT = core
CONFIG -= app_bundle

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/lib.pri)


DISTFILES += \
    README.md


