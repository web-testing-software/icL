
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

CONFIG += c++17 no_include_pwd
QMAKE_CXXFLAGS += -std=c++1z

INCLUDEPATH += $$ICL_ROOT/src

CONFIG(debug, debug|release) {
}


CONFIG(debug, debug|release) {
    BUILDTYPE = debug
    DEFINES += icL_debug
}
else {
    BUILDTYPE = release
}
