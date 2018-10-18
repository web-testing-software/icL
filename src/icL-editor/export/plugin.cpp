#include "plugin.h"

#include "editordrawing.h"

EditorPlugin::EditorPlugin(QObject * parent)
	: QQmlExtensionPlugin(parent) {}

void EditorPlugin::registerTypes(const char * uri) {
	Q_ASSERT(uri == QLatin1String("icL.Editor"));

	qmlRegisterType<icL::editor::EditorDrawing>(uri, 1, 0, "Editor");

	qDebug() << uri << "loaded";
}
