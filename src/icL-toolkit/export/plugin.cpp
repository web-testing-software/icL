#include "plugin.h"

#include "panels.h"

#include <icL-toolkit/panels/browser.h>
#include <icL-toolkit/panels/code.h>
#include <icL-toolkit/panels/debug.h>
#include <icL-toolkit/utils/mousetracker.h>

#include <QQmlEngine>

ToolkitPlugin::ToolkitPlugin(QObject * parent)
    : QQmlExtensionPlugin(parent) {}

void ToolkitPlugin::registerTypes(const char * uri) {
    Q_ASSERT(uri == QLatin1String("icL.Toolkit"));

    qmlRegisterType<icL::toolkit::panels::Browser>();
    qmlRegisterType<icL::toolkit::panels::Code>();
    qmlRegisterType<icL::toolkit::panels::Debug>();
    qmlRegisterType<icL::toolkit::panels::Panels>(uri, 1, 0, "Panels");
    qmlRegisterType<icL::toolkit::utils::MouseTracker>(uri, 1, 0, "MouseTrack");
}
