include($$ICL_ROOT/pri_files/common.pri)
include($$ICL_ROOT/pri_files/os.pri)

DESTDIR = $$ICL_ROOT/bin/$$BUILDTYPE/$$OS
LIBS += -L$$ICL_ROOT/bin/$$BUILDTYPE/$$OS/lib

unix {
        target.path = /usr/bin
        INSTALLS += target
}

#LIBS += -l-icL-look
#LIBS += -l-icL-editor
#LIBS += -l-icl-context-base
#LIBS += -l-icl-context-complex
#LIBS += -l-icl-context-control
#LIBS += -l-icl-context-data
#LIBS += -l-icl-inter
#LIBS += -l-icl-vm
#LIBS += -l-icl-dsv
