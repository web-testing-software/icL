#include "resource.h"

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
	// TODO: Write this function later
}

QString Resource::getIcon() {
	return "resource.svg";
}

}  // namespace icL::toolkit::session
