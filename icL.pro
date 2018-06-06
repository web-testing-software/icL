
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
    graduation/src2pdf.sh \
    graduation/пояснительная_записка.epub \
    graduation/руководство_пользователя.epub \
    graduation/техническое_задание.epub \
    graduation/Исходники.pdf \
    graduation/пояснительная_записка.pdf \
    graduation/презентация.pdf \
    graduation/руководство_пользователя.pdf \
    graduation/техническое_задание.pdf \
    graduation/пояснительная_записка.odt \
    graduation/руководство_пользователя.odt \
    graduation/техническое_задание.odt \
    graduation/презенация.pptx \
    bin/release/linux/update.sh \
    bin/release/linux/uninstall.sh \
    bin/release/linux/install.sh \
    bin/release/linux/extra/icL.desktop \
    bin/release/linux/extra/icL.svg
