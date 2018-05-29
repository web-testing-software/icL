 
TEMPLATE = subdirs

SUBDIRS = \
        memory \
        logic \
        vm \
        inter \
        app \
        context

memory.subdir = icl-memory
logic.subdir = icl-logic
context.subdir = icl-context
vm.subdir = icl-vm
inter.subdir = icl-inter
app.subdir = icl-app

logic.depends = memory
context.depends = memory logic
inter.depends = logic context
vm.depends = context memory inter
app.depends = memory vm inter
#app.depends = vm

DISTFILES += \
    ./src2pdf.sh
