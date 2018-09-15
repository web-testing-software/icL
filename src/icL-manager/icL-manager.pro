
QT       += core gui qml

TARGET = icL-manager
TEMPLATE = app

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/app.pri)


DISTFILES += \
    README.md

SOURCES += \
    main.cpp


