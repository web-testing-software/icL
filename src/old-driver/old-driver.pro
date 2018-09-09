TARGET = -icl-driver
TEMPLATE = lib

QT = core network gui widgets
CONFIG -= app_bundle

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/lib.pri)

HEADERS += \
    w3c/chrome.h \
    w3c/w3c.h \
    icl/icl.h \
    icl/qml.h \
    icl/cpp.h

SOURCES += \
    w3c/chrome.cpp \
    w3c/w3c.cpp \
    icl/icl.cpp \
    icl/qml.cpp \
    icl/cpp.cpp
