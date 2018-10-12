#include "resource.h"

#include "../utils/remotecall.h"
#include "project.h"

#include <QDir>
#include <QFile>
#include <QVariant>

namespace icL::toolkit::session {

Resource::Resource(Item * parent)
	: Finaly(parent) {}

bool Resource::setPath(const QString & path) {
	return checkIfFileExist(path, resourceName);
}

int Resource::columnCount() {
	return 1;
}

QVariant Resource::data(int column) {
	if (column == 0) {
		return {resourceName};
	}
	else {
		return {};
	}
}

int Resource::selfIndex() {
	if (dynamic_cast<Project *>(m_parent)->hasLibs()) {
		return 2;
	}
	else {
		return 1;
	}
}

QString Resource::getIcon() {
	return "resource.svg";
}

enum Actions { Delete = 0 };

const utils::Actions & Resource::getActionsList() {
	static utils::Actions actions = {
	  new utils::RemoteCall(Actions::Delete, QObject::tr("Delete"), {})};

	return actions;
}

bool Resource::runAction(utils::RemoteCall * call) {}

}  // namespace icL::toolkit::session
