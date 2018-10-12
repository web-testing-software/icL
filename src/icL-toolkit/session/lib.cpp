#include "lib.h"

#include <QFile>
#include <QVariant>

namespace icL::toolkit::session {

Lib::Lib(Item * parent)
	: Finaly(parent) {}

bool Lib::setPath(const QString & path) {
	QFile file{path};

	if (!file.open(QFile::ReadOnly)) {
		return false;
	}

	file.close();

	int slash = path.lastIndexOf('/');
	libname   = path.mid(slash + 1);

	return true;
}

int Lib::columnCount() {
	return 1;
}

QVariant Lib::data(int column) {
	if (column == 0) {
		return {libname};
	}
	else {
		return {};
	}
}

int Lib::selfIndex() {
	return 1;
}

QString Lib::getIcon() {
	return "lib.svg";
}

}  // namespace icL::toolkit::session
