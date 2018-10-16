#include "plugin.h"

#include "editor.h"

EditorPlugin::EditorPlugin(QObject * parent)
	: QQmlExtensionPlugin(parent) {}

void EditorPlugin::registerTypes(const char * uri) {
	Q_ASSERT(uri == QLatin1String("icL.Editor"));

	qmlRegisterType<icL::editor::Editor>(uri, 1, 0, "Editor");
}
