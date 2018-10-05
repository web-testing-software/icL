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

#include <QtDebug>
#include <QQmlEngine>

LookPlugin::LookPlugin(QObject * parent)
	: QQmlExtensionPlugin(parent) {}

void LookPlugin::registerTypes(const char * uri) {
//	Q_ASSERT(uri == QLatin1String("icL.Look"));
	qDebug() << uri;

//	qmlRegisterType<icL::editor::look::base::Base>();
//	qmlRegisterType<TextLook>(uri, 1, 0, "TextLook");
//	qmlRegisterType<Effect>(uri, 1, 0, "Effect");
//	qmlRegisterType<EffectAdv>(uri, 1, 0, "EffectAdv");
//	qmlRegisterType<Link>(uri, 1, 0, "Link");
//	qmlRegisterType<LinkAdv>(uri, 1, 0, "LinkAdv");
//	qmlRegisterType<CharFormatBase>(uri, 1, 0, "CharFormatBase");
//	qmlRegisterType<CharFormat>(uri, 1, 0, "CharFormat");
//	qmlRegisterType<Editor>(uri, 1, 0, "Editor");
//	qmlRegisterType<Highlight>(uri, 1, 0, "Highlight");
//	qmlRegisterType<Line>(uri, 1, 0, "Line");
//	qmlRegisterType<CentralSide>(uri, 1, 0, "CentralSide");
//	qmlRegisterType<Floating>(uri, 1, 0, "Floating");
//	qmlRegisterType<Issue>(uri, 1, 0, "Issue");
//	qmlRegisterType<LeftSide>(uri, 1, 0, "LeftSide");
//	qmlRegisterType<SessionWindow>(uri, 1, 0, "SessionWindow");
//	qmlRegisterType<TopBar>(uri, 1, 0, "TopBar");
//	qmlRegisterType<Tree>(uri, 1, 0, "Tree");
//	qmlRegisterType<Input>(uri, 1, 0, "Input");
//	qmlRegisterType<ListItem>(uri, 1, 0, "ListItem");
//	qmlRegisterType<Side>(uri, 1, 0, "Side");
//	qmlRegisterType<StartWindow>(uri, 1, 0, "StartWindow");
//	qmlRegisterType<Look>(uri, 1, 0, "Look");
	qmlRegisterType<TextLook>();
	qmlRegisterType<Effect>();
	qmlRegisterType<EffectAdv>();
	qmlRegisterType<Link>();
	qmlRegisterType<LinkAdv>();
	qmlRegisterType<CharFormatBase>();
	qmlRegisterType<CharFormat>();
	qmlRegisterType<Editor>();
	qmlRegisterType<Highlight>();
	qmlRegisterType<Line>();
	qmlRegisterType<CentralSide>();
	qmlRegisterType<Floating>();
	qmlRegisterType<Issue>();
	qmlRegisterType<LeftSide>();
	qmlRegisterType<SessionWindow>();
	qmlRegisterType<TopBar>();
	qmlRegisterType<Tree>();
	qmlRegisterType<Input>();
	qmlRegisterType<ListItem>();
	qmlRegisterType<Side>();
	qmlRegisterType<StartWindow>();
	qmlRegisterType<Look>(uri, 1, 0, "Look");
}
