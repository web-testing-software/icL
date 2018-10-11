#include "resource.h"

#include <QVariant>

namespace icL::toolkit::session {

Resource::Resource(Item * parent)
	: Finaly(parent) {}

int Resource::columnCount() {
	return 1;
}

QVariant Resource::data(int column) {
	if (column == 0) {
		return {resurceName};
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
