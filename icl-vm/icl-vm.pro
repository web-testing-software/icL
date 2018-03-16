
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
    allcommands.h \
    allheaders.h \
    parser.h \
    database/basic/editing.h \
    database/basic/output.h \
    debugger/basic/testing.h \
    driver/managecontent/frames.h \
    driver/navigation/navigation.h \
    driver/navigation/wainting.h \
    input/keyboard/complexeventk.h \
    input/mouse/complexeventm.h \
    javascript/basejs/get.h \
    javascript/basejs/runjs.h \
    javascript/basejs/set.h \
    javascript/dom/elementstest.h \
    javascript/dom/filterelements.h \
    javascript/dom/findelements.h \
    language/constant/readc.h \
    language/control/comment.h \
    language/control/multishot.h \
    language/control/singleshot.h \
    language/localmemory/readl.h \
    language/localmemory/writel.h \
    language/statestorange/reads.h \
    language/statestorange/writes.h \
    allcommands.h \
    allheaders.h \
    system/functions/server.h \
    system/main/driver.h \
    system/main/ifstackstate.h \
    vm_errors.h

SOURCES += \
    parser.cpp \
    database/basic/editing.cpp \
    database/basic/output.cpp \
    debugger/basic/testing.cpp \
    driver/managecontent/frames.cpp \
    driver/navigation/navigation.cpp \
    driver/navigation/wainting.cpp \
    input/keyboard/complexeventk.cpp \
    input/mouse/complexeventm.cpp \
    javascript/basejs/get.cpp \
    javascript/basejs/runjs.cpp \
    javascript/basejs/set.cpp \
    javascript/dom/elementstest.cpp \
    javascript/dom/filterelements.cpp \
    javascript/dom/findelements.cpp \
    language/constant/readc.cpp \
    language/control/comment.cpp \
    language/control/multishot.cpp \
    language/control/singleshot.cpp \
    language/localmemory/readl.cpp \
    language/localmemory/writel.cpp \
    language/statestorange/reads.cpp \
    language/statestorange/writes.cpp \
    system/functions/server.cpp \
    system/main/driver.cpp \
    system/main/ifstackstate.cpp

DEFINES += QT_DEPRECATED_WARNINGS
