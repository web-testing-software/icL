#include "chars.h"

namespace icL::look {

Chars::Chars(QObject * parent)
	: QObject(parent) {
	if (instance == nullptr) {
		instance = this;
	}
}

void Chars::update() {
	if (instance != nullptr) {
		emit instance->highlight();
	}
}

Chars * Chars::instance = nullptr;

}  // namespace icL::look
