#include "plugin.h"

#include "drawing.h"

EditorPlugin::EditorPlugin(QObject * parent)
	: QQmlExtensionPlugin(parent) {}

void EditorPlugin::registerTypes(const char * uri) {
	Q_ASSERT(uri == QLatin1String("icL.Editor"));

	qmlRegisterType<icL::editor::Drawing>(uri, 1, 0, "Editor");

	qDebug() << uri << "loaded";
}
