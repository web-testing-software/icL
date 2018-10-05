#include "plugin.h"

#include "look.h"

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
	qmlRegisterType<icL::look::Look>(uri, 1, 0, "Look");
}
