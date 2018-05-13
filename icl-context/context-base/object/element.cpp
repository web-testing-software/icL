#include "element.h"

namespace vm::context::object {



Element::Element(memory::DataState* container, const QString& varName)
	: Object(container, varName) {}

Element::Element(const QVariant& rvalue, bool readonly)
	: Object(rvalue, readonly) {}

Element::Element(const Object* const object)
	: Object(object) {}



bool Element::toBoolean() {
	return false;
}

int Element::toInt() {
	return 0;
}

double Element::toDouble() {
	return 0.0;
}

const QString Element::toString() {
	return QString{};
}

const QStringList Element::toList() {
	return QStringList{};
}

}  // namespace vm::context::object
