#include "plugin.h"

#include "editorstylehub.h"

EditorPlugin::EditorPlugin(QObject * parent)
	: QQmlExtensionPlugin(parent) {}

void EditorPlugin::registerTypes(const char * uri) {
	Q_ASSERT(uri == QLatin1String("icL.Editor"));

	qmlRegisterType<icL::editor::EditorStyleHub>(uri, 1, 0, "Editor");
}
