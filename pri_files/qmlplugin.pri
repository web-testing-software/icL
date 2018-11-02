include(lib.pri)

DESTDIR = $$ICL_ROOT/bin/$$BUILDTYPE/$$OS/$$replace(uri, \\., /)

copy_qmldir.target = $$DESTDIR/qmldir
copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
copy_qmldir.commands = $(MKDIR) \"$$DESTDIR\"; \
    $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"

copy_qmltypes.target = $$DESTDIR/$$QML_TYPES
copy_qmltypes.depends = $$_PRO_FILE_PWD_/$$QML_TYPES
copy_qmltypes.commands = $(COPY_FILE) \"$$replace(copy_qmltypes.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmltypes.target, /, $$QMAKE_DIR_SEP)\"

QMAKE_EXTRA_TARGETS += copy_qmldir copy_qmltypes
PRE_TARGETDEPS += $$copy_qmldir.target $$copy_qmltypes.target

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += qmldir
} 
