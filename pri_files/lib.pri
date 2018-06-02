include($$ICL_ROOT/pri_files/common.pri)
include($$ICL_ROOT/pri_files/os.pri)

CONFIG(debug, debug|release) {
    DESTDIR = $$ICL_ROOT/bin/debug/$$OS/lib
}
else {
    DESTDIR = $$ICL_ROOT/bin/release/$$OS/lib
}

unix {
    target.path = /usr/lib
    INSTALLS += target
}
