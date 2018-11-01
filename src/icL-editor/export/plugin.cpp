#include "plugin.h"

#include "../self/cursorsarea.h"
#include "../self/editorinternal.h"
#include "../self/linenumbers.h"
#include "../self/opacitymask.h"

EditorPlugin::EditorPlugin(QObject * parent)
    : QQmlExtensionPlugin(parent) {}

void EditorPlugin::registerTypes(const char * uri) {
	Q_ASSERT(uri == QLatin1String("icL.Editor"));

	qDebug() << "editor reg" << qmlRegisterType<icL::editor::Logic>();
	qDebug() << "editor reg" << qmlRegisterType<icL::editor::Drawing>();
	qDebug() << "editor reg" << qmlRegisterType<icL::editor::History>();
	qDebug() << "editor reg" << qmlRegisterType<icL::editor::Keyboard>();
	qDebug() << "editor reg" << qmlRegisterType<icL::editor::Mouse>();
	qDebug() << "editor reg"
			 << qmlRegisterType<icL::editor::EditorInternal>(
				  uri, 1, 0, "EditorInternal");
	qDebug() << "editor reg"
			 << qmlRegisterType<icL::editor::LineNumbers>(
				  uri, 1, 0, "LineNumbers");
	qDebug() << "editor reg"
			 << qmlRegisterType<icL::editor::OpacityMask>(
				  uri, 1, 0, "EditorOpacityMask");
	qDebug() << "editor reg cursors"
			 << qmlRegisterType<icL::editor::CursorsArea>(
				  uri, 1, 0, "CursorsArea");
}
