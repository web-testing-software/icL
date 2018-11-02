#include "project.h"

#include "../utils/remotecall.h"
#include "libs.h"
#include "resources.h"
#include "script.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringBuilder>
#include <QTextStream>

namespace icL::toolkit::session {

Project::Project(Item * parent)
    : Item(parent) {}

Project::~Project() {
	delete script;
	delete resources;
	delete libs;
}

bool Project::loadProject(const QString & path) {
	QFile       file{path + "/project.json"};
	QTextStream stream{&file};

	if (!file.open(QFile::ReadOnly)) {
		return false;
	}

	auto doc = QJsonDocument::fromJson(stream.readAll().toUtf8());
	auto obj = doc.object();

	if (!obj["icL-project"].isString()) {
		return false;
	}

	m_name    = obj["icL-project"].toString();
	script    = new Script(this);
	resources = new Resources(this);
	libs      = new Libs(this);

	bool res = true;

	res = res && script->setPath(path % '/' % obj["script"].toString());
	res = res && resources->setResourceList(
	               path, obj["resources"].toArray().toVariantList());
	res = res && libs->setLibsList(path, obj["libs"].toArray().toVariantList());

	return res;
}

bool Project::hasLibs() {
	return libs->childCount() > 0;
}

tree::Item * Project::child(int row) {
	tree::Item * ret = nullptr;

	switch (row) {
	case 0:
		ret = script;
		break;

	case 1:
		if (libs->childCount() > 0) {
			ret = libs;
		}
		else {
			ret = resources;
		}
		break;

	case 2:
		ret = resources;
		break;
	}

	return ret;
}

int Project::childCount() {
	int ret = 1;

	if (libs->childCount() > 0) {
		ret++;
	}
	if (resources->childCount() > 0) {
		ret++;
	}

	return ret;
}

int Project::columnCount() {
	return 1;
}

QVariant Project::data(int column) {
	if (column == 0) {
		return {m_name};
	}

	return {};
}

QString Project::getIcon() {
	return "project.svg";
}

enum Actions { NewLib = 0, NewResource = 1 };

const utils::Actions & Project::getActionsList() {
	static utils::Actions actions = {
	  new utils::RemoteCall(
	    Actions::NewLib, QObject::tr("New library"),
	    {new utils::RemoteArg(QObject::tr("Library name"))}),
	  new utils::RemoteCall(
	    Actions::NewResource, QObject::tr("New resource"), {})};

	return actions;
}

bool Project::runAction(utils::RemoteCall * call) {}

}  // namespace icL::toolkit::session
