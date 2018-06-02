
TEMPLATE = subdirs

SUBDIRS = \
        linux \ # non compiling project, just file continer
        memory \
        logic \
        vm \
        inter \
        app \
        context

linux.subdir    = bin/release/linux
memory.subdir   = src/icl-memory
logic.subdir    = src/icl-logic
context.subdir  = src/icl-context
vm.subdir       = src/icl-vm
inter.subdir    = src/icl-inter
app.subdir      = src/icl-app

logic.depends   = memory
context.depends = memory logic
inter.depends   = logic context
vm.depends      = context memory inter
app.depends     = memory inter vm

DISTFILES += \
    ./src2pdf.sh
