#-------------------------------------------------
#
# Project created by QtCreator 2017-08-16T12:56:38
#
#-------------------------------------------------

TEMPLATE = subdirs

SUBDIRS = \
        memory \
        vm \
        ce \
        cp \
        ide \
        il \
        manager \
        share \
        sv \
        wd \
        worker

memory.subdir   = src/icl-memory
vm.subdir       = src/icl-vm
ce.subdir       = src/icl-ce
cp.subdir       = src/icl-cp
ide.subdir      = src/icl-ide
il.subdir       = src/icl-il
manager.subdir  = src/icl-manager
share.subdir    = src/icl-share
sv.subdir       = src/icl-sv
wd.subdir       = src/icl-wd
worker.subdir   = src/icl-worker

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
    CONTRIBUTING.md \
    layouts/dark/*.svg \
    layouts/light/*.svg \
    layouts/structure/*.svg
