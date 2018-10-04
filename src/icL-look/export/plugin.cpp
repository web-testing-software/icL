#include "plugin.h"

#include "look.h"

#include <icL-editor/look/chars.h>
#include <icL-look/base/effectadv.h>
#include <icL-look/base/linkadv.h>
#include <icL-look/editor/charformat.h>
#include <icL-look/editor/editor.h>
#include <icL-look/editor/highlight.h>
#include <icL-look/editor/line.h>
#include <icL-look/session/centralside.h>
#include <icL-look/session/floating.h>
#include <icL-look/session/issue.h>
#include <icL-look/session/leftside.h>
#include <icL-look/session/sessionwindow.h>
#include <icL-look/session/topbar.h>
#include <icL-look/session/tree.h>
#include <icL-look/start/input.h>
#include <icL-look/start/side.h>
#include <icL-look/start/startwindow.h>

#include <QQmlEngine>

namespace icL::look {

Plugin::Plugin(QObject * parent)
	: QQmlExtensionPlugin(parent) {}

void Plugin::registerTypes(const char * uri) {
	Q_ASSERT(uri == QLatin1String("Look"));

	qmlRegisterType<icL::look::base::Text>();
	qmlRegisterType<icL::look::base::Effect>();
	qmlRegisterType<icL::look::base::EffectAdv>();
	qmlRegisterType<icL::look::base::Link>();
	qmlRegisterType<icL::look::base::LinkAdv>();
	qmlRegisterType<icL::look::editor::CharFormatBase>();
	qmlRegisterType<icL::look::editor::CharFormat>();
	qmlRegisterType<icL::look::editor::Editor>();
	qmlRegisterType<icL::look::editor::Highlight>();
	qmlRegisterType<icL::look::editor::Line>();
	qmlRegisterType<icL::look::session::CentralSide>();
	qmlRegisterType<icL::look::session::Floating>();
	qmlRegisterType<icL::look::session::Issue>();
	qmlRegisterType<icL::look::session::LeftSide>();
	qmlRegisterType<icL::look::session::SessionWindow>();
	qmlRegisterType<icL::look::session::TopBar>();
	qmlRegisterType<icL::look::session::Tree>();
	qmlRegisterType<icL::look::start::Input>();
	qmlRegisterType<icL::look::start::ListItem>();
	qmlRegisterType<icL::look::start::Side>();
	qmlRegisterType<icL::look::start::StartWindow>();
	qmlRegisterType<icL::look::Look>(uri, 1, 0, "Look");
}

}  // namespace icL::look
