include($$ICL_ROOT/pri_files/common.pri)
include($$ICL_ROOT/pri_files/os.pri)

DESTDIR = $$ICL_ROOT/bin/$$BUILDTYPE/$$OS/lib

unix {
    target.path = /usr/lib
    INSTALLS += target
}
