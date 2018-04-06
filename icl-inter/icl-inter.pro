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
    models/class_diagram.plantuml \
    models/parse_argument.plantuml \
    models/parse_cast.plantuml \
    models/parse_code_block_end.plantuml \
    models/parse_comment.plantuml \
    models/parse_content_bounds.plantuml \
    models/parse_keyword.plantuml \
    models/parse_logical_exmpression.plantuml \
    models/parse_next.plantuml \
    models/parse_special_contructions.plantuml \
    models/parse_stack_variable.plantuml \
    models/parse_state_variable.plantuml \
    models/prepare_js_crossfire.plantuml \
    models/prepare_js_set.plantuml \
    models/uml_style.iuml \

HEADERS += \
    interpreter.h \
    flayer.h

SOURCES += \
    interpreter.cpp \
    flayer.cpp
