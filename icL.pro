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

# libs
memory.subdir   = src/icL-memory
vm.subdir       = src/icL-vm
ce.subdir       = src/icL-ce
cp.subdir       = src/icL-cp
il.subdir       = src/icL-il
sv.subdir       = src/icL-sv
wd.subdir       = src/icL-wd

# apps
ide.subdir      = src/icL-ide
share.subdir    = src/icL-share
manager.subdir  = src/icL-manager
worker.subdir   = src/icL-worker

DISTFILES += \
    Doxyfile \
    templates/doxy_style.css \
    templates/doxy_header.html \
    templates/doxy_footer.html \
    bin/release/linux/update.sh \
    bin/release/linux/uninstall.sh \
    bin/release/linux/install.sh \
    bin/release/linux/extra/icL.desktop \
    bin/release/linux/extra/icL.svg \
    standard/standard_for_icl_1.0.0_draft.tex \
    standard/russian/*.tex \
    standard/moldavian/*.tex \
    standard/english/*.tex \
    README.md \
    standard/README.md \
    clang-format \
    standart/README.md \
    CONTRIBUTING.md \
    layouts/dark/*.svg \
    layouts/light/*.svg \
    layouts/structure/*.svg \
    layouts/models/*.svg \
    images/*.png \
    technologies/README.md
