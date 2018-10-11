#include "resources.h"

namespace icL::toolkit::session {

Resources::Resources(Item * parent)
	: Folder(parent) {}

QVariant Resources::data(int column) {
	if (column == 0) {
		return {QObject::tr("Resources")};
	}
	else {
		return {};
	}
}

QString Resources::getIcon() {
	return "resources.svg";
}

}  // namespace icL::toolkit::session
