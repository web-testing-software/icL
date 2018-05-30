
QT = core quick
CONFIG -= app_bundle

TARGET = -icl-vm
TEMPLATE = lib

ICL_ROOT = $$PWD/..
DESTDIR = $$ICL_ROOT/bin/lib

CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++1z

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

INCLUDEPATH += ..
INCLUDEPATH -= .

unix {
	target.path = /usr/lib
	INSTALLS += target
}

HEADERS += \
    server.h \
    virtualmachine.h \
    vmstack.h

SOURCES += \
    server.cpp \
    virtualmachine.cpp \
    vmstack.cpp

DEFINES += QT_DEPRECATED_WARNINGS

DISTFILES += \
    models/uml_style.iuml \
    models/class_diagram.plantuml \
    models/find_executable.plantuml \
    models/vm_step.plantuml \
    models/vms_interrupt.plantuml \
    models/interpreteur_life_circle.plantuml \
    models/sequence_crossfire.plantuml \
    models/sequence_ExecuteJS.plantuml \
    models/sequence_GoTo.plantuml \
    models/sequence_waitForLoading_correctCall.plantuml \
    models/sequence_waitForLoading_wrongCall.plantuml \
    models/server_executeJS.plantuml \
    models/server_finishJS.plantuml \
    models/server_finishLoad.plantuml \
    models/server_goTo.plantuml \
    models/server_onRequestExecuteJS_lambda.plantuml \
    models/server_onRequestExecuteJS.plantuml \
    models/server_onRequestGoTo.plantuml \
    models/server_onRequestWaitForLoad.plantuml \
    models/server_waitForLoading.plantuml \
    models/webEngine_onLoadStatusChanged.plantuml \
    models/sequence_js_code_run.plantuml \
    models/sequence_interrupt.plantuml
