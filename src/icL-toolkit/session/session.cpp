#include "session.h"

namespace icL::toolkit::session {

Session::Session()
	: Folder(nullptr) {}

QVariant Session::data(int) {
	return QVariant();
}

tree::Item * Session::parent() {
	return nullptr;
}

QString Session::getIcon() {
	return {};
}

}  // namespace icL::toolkit::session
