 
TEMPLATE = subdirs

SUBDIRS = \
        vm \
        inter \
        app

vm.subdir = icl-vm
inter.subdir = icl-inter
app.subdir = icl-app

inter.depends = vm
app.depends = vm inter
