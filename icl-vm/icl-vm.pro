
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
    models/uml_style.iuml \
    models/class_diagram.plantuml \
    models/find_executable.plantuml \
    models/interrupt.plantuml \
    models/js_code_run.plantuml \
    models/uml_style.iuml \
    models/vm_step.plantuml \
    models/vms_interrupt.plantuml \
    models/class_diagram.plantuml \
    models/find_executable.plantuml \
    models/interpreteur_life_circle.plantuml \
    models/interrupt.plantuml \
    models/js_code_run.plantuml \
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
    models/uml_style.iuml \
    models/vm_step.plantuml \
    models/vms_interrupt.plantuml \
    models/webEngine_onLoadStatusChanged.plantuml
