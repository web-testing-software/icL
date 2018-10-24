#include "finaly.h"

#include <QFile>

namespace icL::toolkit::tree {

Finaly::Finaly(Item * parent)
    : Item(parent) {}

Item * Finaly::child(int /*row*/) {
	return nullptr;
}

int Finaly::childCount() {
	return 0;
}

bool Finaly::checkIfFileExist(const QString & path, QString & field) {
	QFile file{path};

	if (!file.open(QFile::ReadOnly)) {
		return false;
	}

	file.close();

	int slash = path.lastIndexOf('/');
	field     = path.mid(slash + 1);

	return true;
}

}  // namespace icL::toolkit::tree
