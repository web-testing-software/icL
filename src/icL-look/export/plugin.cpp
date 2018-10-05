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
