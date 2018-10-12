#include "session.h"

#include "project.h"

#include <QDir>
#include <QJsonArray>
#include <QJsonObject>
#include <QStringBuilder>

namespace icL::toolkit::session {

Session::Session()
	: Folder(nullptr) {}

bool Session::loadSession(const QJsonObject & obj) {
	if (!obj["icL-session"].isString()) {
		return false;
	}

	clear();

	m_name = obj["icL-session"].toString();

	bool    ret  = true;
	QString path = QDir::homePath() % "/.icL/" % m_name % '/';

	for (const auto & strValue : obj["projects"].toArray()) {
		auto * project = new Project(this);

		ret = ret && project->loadProject(path + strValue.toString());

		children.append(project);

		if (!ret)
			break;
	}

	return ret;
}

QVariant Session::data(int) {
	return QVariant();
}

tree::Item * Session::parent() {
	return nullptr;
}

QString Session::getIcon() {
	return {};
}

const utils::Actions & Session::getActionsList() {}

bool Session::runAction(utils::RemoteCall * call) {}

}  // namespace icL::toolkit::session
