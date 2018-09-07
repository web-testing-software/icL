#-------------------------------------------------
#
# Project started 2016-12-03
# Project alived 2017-07-28
# Project created by QtCreator 2017-08-16T08:13:21
#
#-------------------------------------------------

QT       += core gui widgets webengine sql

TARGET = icL
TEMPLATE = app

ICL_ROOT = $$PWD/../..

CONFIG(debug, debug|release) {
    DEFINES += ICL_ADD_TEST_DB_DATA
}

include($$ICL_ROOT/pri_files/app.pri)

SOURCES += \
        main.cpp \
	backend/helper.cpp \
        data_management/database.cpp \
	data_management/dialdescription.cpp

HEADERS += \
	backend/helper.h \
        data_management/database.h \
	data_management/dialdescription.h

RESOURCES += \
    qml/main.qrc \
    sql/sql.qrc \
    images/images.qrc

DISTFILES += \
    uml2png.sh \
    uml2svg.sh \
    models/uml_style.iuml \
    models/use_case.plantuml \
    models/modules.plantuml \
    _clang-format

