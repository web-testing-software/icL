# ide - integrated development environment

QT       += core widgets gui qml webengine sql

TARGET = icL-ide
TEMPLATE = app

ICL_ROOT = $$PWD/../..

include($$ICL_ROOT/pri_files/app.pri)


SOURCES += \
    main.cpp

RESOURCES += \
    qml/qml.qrc


DISTFILES += \
    README.md \
    models/*.*uml
