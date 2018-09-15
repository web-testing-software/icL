# ide - integrated development environment

QT       += core gui qml webengine sql

TARGET = icL-ide
TEMPLATE = app

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/app.pri)


DISTFILES += \
    README.md

SOURCES += \
    main.cpp

