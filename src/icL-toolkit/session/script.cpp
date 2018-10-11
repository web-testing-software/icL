#include "script.h"

#include <QVariant>

namespace icL::toolkit::session {

Script::Script(Item * parent)
	: Finaly(parent) {}

int Script::columnCount() {
	return 1;
}

QVariant Script::data(int column) {
	return {name};
}

int Script::selfIndex() {
	return 0;
}

QString Script::getIcon() {
	return "icL-file.svg";
}

}  // namespace icL::toolkit::session
