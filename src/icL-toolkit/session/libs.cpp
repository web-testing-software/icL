#include "libs.h"

#include <QVariant>

namespace icL::toolkit::session {

Libs::Libs(Item * parent)
	: Folder(parent) {}

QVariant Libs::data(int column) {
	if (column == 0) {
		return {QObject::tr("Libs")};
	}
	else {
		return {};
	}
}

QString Libs::getIcon() {
	return "libs.svg";
}

}  // namespace icL::toolkit::session
