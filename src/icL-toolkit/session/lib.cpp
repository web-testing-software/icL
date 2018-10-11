#include "lib.h"

#include <QVariant>

namespace icL::toolkit::session {

Lib::Lib(Item * parent)
	: Finaly(parent) {}

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
