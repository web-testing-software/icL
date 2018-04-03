
QT = core
CONFIG -= app_bundle

TARGET = icl-vm
TEMPLATE = lib

CONFIG += staticlib
CONFIG += c++1z
QMAKE_CXXFLAGS += -std=c++1z

INCLUDEPATH += ../

unix {
	target.path = /usr/lib
	INSTALLS += target
}

HEADERS += \
    server.h \
    virtualmachine.h

SOURCES += \
    server.cpp \
    virtualmachine.cpp

DEFINES += QT_DEPRECATED_WARNINGS

DISTFILES += \
    models/uml_style.iuml
