#include "resource.h"

#include <QDir>
#include <QFile>
#include <QVariant>

namespace icL::toolkit::session {

Resource::Resource(Item * parent)
	: Finaly(parent) {}

bool Resource::setPath(const QString & path) {
	QFile file{path};

	if (!file.open(QFile::ReadOnly)) {
		return false;
	}

	file.close();

	int slash    = path.lastIndexOf('/');
	resourceName = path.mid(slash + 1);

	return true;
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
