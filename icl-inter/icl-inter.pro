TARGET = icl-inter
TEMPLATE = lib

QT = core
CONFIG -= app_bundle

CONFIG += staticlib
CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

INCLUDEPATH += ../

unix {
	target.path = /usr/lib
	INSTALLS += target
}

DISTFILES += \
    uml/!void.plantuml \
    uml/database.plantuml \
    uml/debugger.plantuml \
    uml/if.plantuml \
    uml/query.plantuml \
    uml/read.plantuml \
    uml/switch.plantuml \
    uml/tab.plantuml \
    uml/js.plantuml \
    uml/logic_exp.plantuml \
    uml/new.plantuml \
    uml/on.plantuml \
    uml/void.plantuml \
    uml/wait.plantuml \
    uml/wb_style.iuml \
    uml/web_element.plantuml \
    uml/web_elements.plantuml \
    uml2/uml_style.iuml \
    uml2/comment.plantuml \
    uml2/global.plantuml \
    uml2/js.plantuml \
    uml2/r_w_context.plantuml

HEADERS += \
    interpreter.h \
    flayer.h

SOURCES += \
    interpreter.cpp \
    flayer.cpp
