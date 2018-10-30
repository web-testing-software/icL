#include "plugin.h"

#include "../self/advanced.h"
#include "../self/linenumbers.h"
#include "../self/opacitymask.h"

EditorPlugin::EditorPlugin(QObject * parent)
    : QQmlExtensionPlugin(parent) {}

void EditorPlugin::registerTypes(const char * uri) {
	Q_ASSERT(uri == QLatin1String("icL.Editor"));

	qmlRegisterType<icL::editor::Logic>();
	qmlRegisterType<icL::editor::Drawing>();
	qmlRegisterType<icL::editor::History>();
	qmlRegisterType<icL::editor::Keyboard>();
	qmlRegisterType<icL::editor::Mouse>();
	qmlRegisterType<icL::editor::Advanced>(uri, 1, 0, "EditorInternal");
	qmlRegisterType<icL::editor::LineNumbers>(uri, 1, 0, "LineNumbers");
	qmlRegisterType<icL::editor::OpacityMask>(uri, 1, 0, "EditorOpacityMask");
}
