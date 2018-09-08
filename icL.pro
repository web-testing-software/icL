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
        dsv

memory.subdir   = src/icl-memory
logic.subdir    = src/icl-logic
context.subdir  = src/icl-context
vm.subdir       = src/icl-vm
driver.subdir   = src/icl-driver
inter.subdir    = src/icl-inter
app.subdir      = src/icl-app
dsv.subdir      = src/icl-dsv

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
    standard/russian/*.tex
