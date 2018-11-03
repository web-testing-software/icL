#include "plugin.h"

#include "../base/effectadv.h"
#include "../base/linkadv.h"
#include "../editor/change.h"
#include "../editor/charformat.h"
#include "../editor/editor.h"
#include "../editor/editorstyle.h"
#include "../editor/highlight.h"
#include "../editor/line.h"
#include "../session/centralside.h"
#include "../session/floating.h"
#include "../session/issue.h"
#include "../session/leftside.h"
#include "../session/sessionwindow.h"
#include "../session/static.h"
#include "../session/topbar.h"
#include "../session/tree.h"
#include "../start/input.h"
#include "../start/side.h"
#include "../start/startwindow.h"
#include "chars.h"
#include "look.h"

#include <QQmlEngine>
#include <QtDebug>

LookPlugin::LookPlugin(QObject * parent)
    : QQmlExtensionPlugin(parent) {}

void LookPlugin::registerTypes(const char * uri) {
	Q_ASSERT(uri == QLatin1String("icL.Look"));

	qmlRegisterType<icL::look::TextLook>();
	qmlRegisterType<icL::look::Effect>();
	qmlRegisterType<icL::look::EffectAdv>();
	qmlRegisterType<icL::look::Link>();
	qmlRegisterType<icL::look::LinkAdv>();
	qmlRegisterType<icL::look::CharFormatBase>();
	qmlRegisterType<icL::look::CharFormat>();
	qmlRegisterType<icL::look::Editor>();
	qmlRegisterType<icL::look::Highlight>();
	qmlRegisterType<icL::look::Line>();
	qmlRegisterType<icL::look::CentralSide>();
	qmlRegisterType<icL::look::Floating>();
	qmlRegisterType<icL::look::Issue>();
	qmlRegisterType<icL::look::LeftSide>();
	qmlRegisterType<icL::look::SessionWindow>();
	qmlRegisterType<icL::look::TopBar>();
	qmlRegisterType<icL::look::Tree>();
	qmlRegisterType<icL::look::Input>();
	qmlRegisterType<icL::look::ListItem>();
	qmlRegisterType<icL::look::Side>();
	qmlRegisterType<icL::look::StartWindow>();
	qmlRegisterType<icL::look::Static>();
	qmlRegisterType<icL::look::EditorStyle>();
	qmlRegisterType<icL::look::Chars>();
	qmlRegisterType<icL::look::ScrollBar>();
	qmlRegisterType<icL::look::Change>();
	qmlRegisterType<icL::look::Look>(uri, 1, 0, "Look");
}
