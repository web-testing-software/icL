#include "plugin.h"

ToolkitPlugin::ToolkitPlugin(QObject * parent)
	: QQmlExtensionPlugin(parent) {}

void ToolkitPlugin::registerTypes(const char * uri) {
	Q_ASSERT(uri == QLatin1String("icL.Toolkit"));

	// No classes yet
}
