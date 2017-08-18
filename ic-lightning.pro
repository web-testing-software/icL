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
		cpp_backend/functions/webelement.cpp \
		cpp_backend/functions/server.cpp \
    cpp_backend/functions/worker.cpp

HEADERS += \
        webbrowser.h \
		cpp_backend/functions/webelement.h \
		cpp_backend/functions/server.h \
    cpp_backend/functions/worker.h

RESOURCES += \
    qml/main.qrc
