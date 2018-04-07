#-------------------------------------------------
#
# Project created by QtCreator 2018-03-31T14:53:03
#
#-------------------------------------------------

QT       -= gui

TARGET = icl-context
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        context.cpp \
    function/function.cpp \
    function/call.cpp \
    function/new.cpp \
    data/data.cpp \
    data/method.cpp \
    data/property.cpp \
    data/alterntive.cpp \
    data/assign.cpp \
    code/main/code.cpp \
    code/main/isolated.cpp \
    code/control/main/control.cpp \
    code/control/main/if.cpp \
    code/control/main/else.cpp \
    code/control/catch/try.cpp \
    code/control/catch/handler.cpp \
    code/control/catch/catch.cpp \
    object/object.cpp \
    object/boolean.cpp \
    object/int.cpp \
    object/double.cpp \
    object/string.cpp \
    object/list.cpp \
    object/void.cpp \
    object/element.cpp \
    data/argument.cpp

HEADERS += \
        context.h \
    function/function.h \
    function/call.h \
    function/new.h \
    data/data.h \
    data/method.h \
    data/property.h \
    data/alterntive.h \
    data/assign.h \
    code/main/code.h \
    code/main/isolated.h \
    code/control/main/control.h \
    code/control/main/if.h \
    code/control/main/else.h \
    code/control/catch/try.h \
    code/control/catch/handler.h \
    code/control/catch/catch.h \
    object/object.h \
    object/boolean.h \
    object/int.h \
    object/double.h \
    object/string.h \
    object/list.h \
    object/void.h \
    object/element.h \
    data/argument.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    models/alternative_execute.plantuml \
    models/alternative_isRightToLeft.plantuml \
    models/assign_execute.plantuml \
    models/assign_isExecutable.plantuml \
    models/class_diagram.plantuml \
    models/context_containsData.plantuml \
    models/context_endContext.plantuml \
    models/context_execute.plantuml \
    models/context_isExecutable.plantuml \
    models/context_isRightToLeft.plantuml \
    models/context_newContext.plantuml \
    models/context_startContext.plantuml \
    models/else_isExecutable.plantuml \
    models/function_isExecutable.plantuml \
    models/if_execute.plantuml \
    models/method_execute.plantuml \
    models/object_containsData.plantuml \
    models/property_execute.plantuml \
    models/uml_style.iuml \
    models/context_order_table.odt \
    models/alternative_checkPrev.plantuml \
    models/argument_checkPrev.plantuml \
    models/assign_checkPrev.plantuml \
    models/call_checkPrev.plantuml \
    models/code_checkPrev.plantuml \
    models/context_checkPrev.plantuml \
    models/context_isResultative.plantuml \
    models/else_checkPrev.plantuml \
    models/handler_checkPrev.plantuml \
    models/if_checkPrev.plantuml \
    models/isolated_checkPrev.plantuml \
    models/method_checkprev.plantuml \
    models/new_checkPrev.plantuml \
    models/object_checkPrev.plantuml \
    models/property_checkPrev.plantuml \
    models/try_checkPrev.plantuml \
    models/if_isExecutable.plantuml \
    models/try_execute.plantuml \
    models/try_isExecutable.plantuml \
    models/handler_isExecutable.plantuml \
    models/code_execute.plantuml \
    models/code_isExecutable.plantuml \
    models/control_isExecutable.plantuml \
    models/control_isRightToLeft.plantuml \
    models/data_isExecutable.plantuml \
    models/call_execute.plantuml \
    models/new_execute.plantuml
