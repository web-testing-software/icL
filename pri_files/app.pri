include($$ICL_ROOT/pri_files/common.pri)
include($$ICL_ROOT/pri_files/os.pri)

CONFIG(debug, debug|release) {
    DESTDIR = $$ICL_ROOT/bin/debug/$$OS
    LIBS += -L$$ICL_ROOT/bin/debug/$$OS/lib
}
else {
    DESTDIR = $$ICL_ROOT/bin/release/$$OS
    LIBS += -L$$ICL_ROOT/bin/release/$$OS/lib
}

unix {
        target.path = /usr/bin
        INSTALLS += target
}

#LIBS += -l-icl-memory
#LIBS += -l-icl-logic
#LIBS += -l-icl-context-base
#LIBS += -l-icl-context-complex
#LIBS += -l-icl-context-control
#LIBS += -l-icl-context-data
#LIBS += -l-icl-inter
#LIBS += -l-icl-vm
#LIBS += -l-icl-dsv
