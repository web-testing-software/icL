 
TEMPLATE = subdirs

SUBDIRS = \
		memory \
		logic \
        vm \
#        inter \
        app

memory.subdir = icl-memory
logic.subdir = icl-logic
vm.subdir = icl-vm
#inter.subdir = icl-inter
app.subdir = icl-app

logic.depends = memory
vm.depends = logic memory
#inter.depends = vm logic
#app.depends = vm inter
app.depends = vm
