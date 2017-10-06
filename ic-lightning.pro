#-------------------------------------------------
#
# Project started 2016-12-03
# Project alived 2017-07-28
# Project created by QtCreator 2017-08-16T08:13:21
#
#-------------------------------------------------

QT       += core gui widgets quickwidgets webengine

TARGET = ic-lightning
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        webbrowser.cpp \
		backend/functions/webelement.cpp \
		backend/functions/server.cpp \
	backend/functions/worker.cpp \
    backend/virtualmachine/language/control/singleshot.cpp \
    backend/virtualmachine/language/control/multishot.cpp \
    backend/virtualmachine/language/control/comment.cpp \
    backend/virtualmachine/language/localmemory/readl.cpp \
    backend/virtualmachine/language/localmemory/writel.cpp \
    backend/virtualmachine/language/statestorange/reads.cpp \
    backend/virtualmachine/language/statestorange/writes.cpp \
    backend/virtualmachine/language/constant/readc.cpp \
    backend/virtualmachine/language/booloperator/logical.cpp \
    backend/virtualmachine/language/booloperator/equal.cpp \
    backend/virtualmachine/language/booloperator/notequal.cpp \
    backend/virtualmachine/language/booloperator/stringlist.cpp \
    backend/virtualmachine/driver/navigation/navigation.cpp \
    backend/virtualmachine/driver/navigation/wainting.cpp \
    backend/virtualmachine/driver/managecontent/frames.cpp \
    backend/virtualmachine/javascript/basejs/runjs.cpp \
    backend/virtualmachine/javascript/basejs/get.cpp \
    backend/virtualmachine/javascript/basejs/set.cpp \
    backend/virtualmachine/javascript/dom/findelements.cpp \
    backend/virtualmachine/javascript/dom/filterelements.cpp \
    backend/virtualmachine/javascript/dom/elementstest.cpp \
    backend/virtualmachine/input/mouse/complexeventm.cpp \
    backend/virtualmachine/input/keyboard/complexeventk.cpp \
    backend/virtualmachine/database/basic/output.cpp \
    backend/virtualmachine/database/basic/editing.cpp \
    backend/virtualmachine/debugger/basic/focus.cpp \
    backend/virtualmachine/parser.cpp \
	backend/virtualmachine/system/main/virtualmachine.cpp \
	backend/virtualmachine/system/main/stackstate.cpp \
	backend/virtualmachine/system/main/memorystate.cpp \
	backend/virtualmachine/system/main/datastate.cpp \
	backend/virtualmachine/system/logic/main/logicblock.cpp \
	backend/virtualmachine/system/logic/main/crossblock.cpp \
	backend/virtualmachine/system/logic/main/trueblock.cpp \
	backend/virtualmachine/system/logic/main/falseblock.cpp \
	backend/virtualmachine/system/logic/main/richblock.cpp \
    backend/virtualmachine/system/logic/cross/notblock.cpp \
    backend/virtualmachine/system/logic/cross/andblock.cpp \
    backend/virtualmachine/system/logic/cross/orblock.cpp \
    backend/virtualmachine/system/logic/cross/xorblock.cpp \
    backend/virtualmachine/system/logic/rich/booleanblock.cpp \
    backend/virtualmachine/system/logic/rich/intblock.cpp \
    backend/virtualmachine/system/logic/rich/doubleblock.cpp \
    backend/virtualmachine/system/logic/rich/stringblock.cpp \
    backend/virtualmachine/system/logic/rich/stringlistblock.cpp

HEADERS += \
        webbrowser.h \
		backend/functions/webelement.h \
		backend/functions/server.h \
	backend/functions/worker.h \
	backend/virtualmachine/allcommands.h \
    backend/virtualmachine/language/control/singleshot.h \
    backend/virtualmachine/language/control/multishot.h \
    backend/virtualmachine/language/control/comment.h \
    backend/virtualmachine/language/localmemory/readl.h \
    backend/virtualmachine/language/localmemory/writel.h \
    backend/virtualmachine/language/statestorange/reads.h \
    backend/virtualmachine/language/statestorange/writes.h \
    backend/virtualmachine/language/constant/readc.h \
    backend/virtualmachine/language/booloperator/logical.h \
    backend/virtualmachine/language/booloperator/equal.h \
    backend/virtualmachine/language/booloperator/notequal.h \
    backend/virtualmachine/language/booloperator/stringlist.h \
    backend/virtualmachine/driver/navigation/navigation.h \
    backend/virtualmachine/driver/navigation/wainting.h \
    backend/virtualmachine/driver/managecontent/frames.h \
    backend/virtualmachine/javascript/basejs/runjs.h \
    backend/virtualmachine/javascript/basejs/get.h \
    backend/virtualmachine/javascript/basejs/set.h \
    backend/virtualmachine/javascript/dom/findelements.h \
    backend/virtualmachine/javascript/dom/filterelements.h \
    backend/virtualmachine/javascript/dom/elementstest.h \
    backend/virtualmachine/input/mouse/complexeventm.h \
    backend/virtualmachine/input/keyboard/complexeventk.h \
    backend/virtualmachine/database/basic/output.h \
    backend/virtualmachine/database/basic/editing.h \
    backend/virtualmachine/debugger/basic/focus.h \
    backend/virtualmachine/parser.h \
    backend/virtualmachine/allheaders.h \
	backend/virtualmachine/system/main/virtualmachine.h \
	backend/virtualmachine/system/main/stackstate.h \
	backend/virtualmachine/system/main/memorystate.h \
	backend/virtualmachine/system/main/datastate.h \
	backend/virtualmachine/system/logic/main/logicblock.h \
	backend/virtualmachine/system/logic/main/crossblock.h \
	backend/virtualmachine/system/logic/main/trueblock.h \
	backend/virtualmachine/system/logic/main/falseblock.h \
	backend/virtualmachine/system/logic/main/richblock.h \
    backend/virtualmachine/system/logic/cross/notblock.h \
    backend/virtualmachine/system/logic/cross/andblock.h \
    backend/virtualmachine/system/logic/cross/orblock.h \
    backend/virtualmachine/system/logic/cross/xorblock.h \
    backend/virtualmachine/system/logic/rich/booleanblock.h \
    backend/virtualmachine/system/logic/rich/intblock.h \
    backend/virtualmachine/system/logic/rich/doubleblock.h \
    backend/virtualmachine/system/logic/rich/stringblock.h \
    backend/virtualmachine/system/logic/rich/stringlistblock.h

RESOURCES += \
    qml/main.qrc


CONFIG += c++11

DISTFILES += \
    models/logic.qmodel
