
QT += core gui

TARGET = icl-vm
TEMPLATE = lib

CONFIG += staticlib C++11


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
    language/booloperator/equal.h \
    language/booloperator/logical.h \
    language/booloperator/notequal.h \
    language/booloperator/stringlist.h \
    language/constant/readc.h \
    language/control/comment.h \
    language/control/multishot.h \
    language/control/singleshot.h \
    language/localmemory/readl.h \
    language/localmemory/writel.h \
    language/statestorange/reads.h \
    language/statestorange/writes.h \
    system/functions/server.h \
    system/functions/webelement.h \
    system/functions/worker.h \
    system/logic/cross/andblock.h \
    system/logic/cross/notblock.h \
    system/logic/cross/orblock.h \
    system/logic/cross/xorblock.h \
    system/logic/main/crossblock.h \
    system/logic/main/falseblock.h \
    system/logic/main/logicblock.h \
    system/logic/main/richblock.h \
    system/logic/main/trueblock.h \
    system/logic/rich/booleanblock.h \
    system/logic/rich/doubleblock.h \
    system/logic/rich/intblock.h \
    system/logic/rich/singleblock.h \
    system/logic/rich/stringblock.h \
    system/logic/rich/stringlistblock.h \
    system/logic/rich/stringliststringblock.h \
    system/main/datastate.h \
    system/main/driver.h \
    system/main/ifstackstate.h \
    system/main/memorystate.h \
    system/main/stackstate.h \
    system/main/virtualmachine.h \
    allcommands.h \
	allheaders.h

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
    language/booloperator/equal.cpp \
    language/booloperator/logical.cpp \
    language/booloperator/notequal.cpp \
    language/booloperator/stringlist.cpp \
    language/constant/readc.cpp \
    language/control/comment.cpp \
    language/control/multishot.cpp \
    language/control/singleshot.cpp \
    language/localmemory/readl.cpp \
    language/localmemory/writel.cpp \
    language/statestorange/reads.cpp \
    language/statestorange/writes.cpp \
    system/functions/server.cpp \
    system/functions/webelement.cpp \
    system/functions/worker.cpp \
    system/logic/cross/andblock.cpp \
    system/logic/cross/notblock.cpp \
    system/logic/cross/orblock.cpp \
    system/logic/cross/xorblock.cpp \
    system/logic/main/crossblock.cpp \
    system/logic/main/falseblock.cpp \
    system/logic/main/logicblock.cpp \
    system/logic/main/richblock.cpp \
    system/logic/main/trueblock.cpp \
    system/logic/rich/booleanblock.cpp \
    system/logic/rich/doubleblock.cpp \
    system/logic/rich/intblock.cpp \
    system/logic/rich/singleblock.cpp \
    system/logic/rich/stringblock.cpp \
    system/logic/rich/stringlistblock.cpp \
    system/logic/rich/stringliststringblock.cpp \
    system/main/datastate.cpp \
    system/main/driver.cpp \
    system/main/ifstackstate.cpp \
    system/main/memorystate.cpp \
    system/main/stackstate.cpp \
	system/main/virtualmachine.cpp

DISTFILES += \
	models/logic.plantuml

DEFINES += QT_DEPRECATED_WARNINGS
