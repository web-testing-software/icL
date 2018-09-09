#-------------------------------------------------
#
# Project created by QtCreator 2017-08-16T12:56:38
#
#-------------------------------------------------

TEMPLATE = subdirs

SUBDIRS = \
        memory \
        logic \
        vm \
        inter \
        app \
        context \
        driver \
        dsv \
        ce \
        cp \
        edit \
        il \
        share \
        sv \
        wd \
        worker

memory.subdir   = src/icl-memory
logic.subdir    = src/old-logic
context.subdir  = src/old-context
vm.subdir       = src/icl-vm
driver.subdir   = src/old-driver
inter.subdir    = src/old-inter
app.subdir      = src/old-app
dsv.subdir      = src/old-dsv
ce.subdir       = src/icl-ce
cp.subdir       = src/icl-cp
edit.subdir     = src/icl-edit
il.subdir       = src/icl-il
share.subdir    = src/icl-share
sv.subdir       = src/icl-sv
wd.subdir       = src/icl-wd
worker.subdir   = src/icl-worker

logic.depends   = memory
context.depends = memory logic
dsv.depends     = context
inter.depends   = logic context
vm.depends      = context memory inter
app.depends     = memory inter vm

DISTFILES += \
    Doxyfile \
    templates/doxy_style.css \
    templates/doxy_header.html \
    templates/doxy_footer.html \
    graduation/src2pdf.sh \
    graduation/bachelor/*.epub \
    graduation/bachelor/*.pdf \
    graduation/bachelor/*.odt \
    graduation/bachelor/*.pptx \
    bin/release/linux/update.sh \
    bin/release/linux/uninstall.sh \
    bin/release/linux/install.sh \
    bin/release/linux/extra/icL.desktop \
    bin/release/linux/extra/icL.svg \
    standard/standard_for_icl_1.0.0_draft.tex \
    standard/russian/*.tex \
    standard/moldavian/*.tex \
    README.md \
    graduation/README.md \
    graduation/bachelor/README.md \
    standart/README.md \
    CONTRIBUTING.md
