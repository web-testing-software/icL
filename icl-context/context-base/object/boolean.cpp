#include "boolean.h"

namespace vm::context::object {



Boolean::Boolean(memory::DataState* container, const QString& varName)
	: Object(container, varName) {}

Boolean::Boolean(const QVariant& rvalue, bool readonly)
	: Object(rvalue, readonly) {}

Boolean::Boolean(const QString& getter, const QString& setter)
	: Object(getter, setter) {}

Boolean::Boolean(const Object* const object)
	: Object(object) {}

memory::Type Boolean::type() const {
	return memory::Type::Boolean;
}

bool Boolean::toBoolean() {
	newValue = getValue();
	return newValue.toBool();
}

int Boolean::toInt() {
	newValue = getValue().toBool() ? 1 : 0;
	return newValue.toInt();
}

double Boolean::toDouble() {
	newValue = getValue().toBool() ? 1.0 : 0.0;
	return newValue.toDouble();
}

const QString Boolean::toString() {
	newValue = getValue().toBool() ? "true" : "false";
	return newValue.toString();
}

const QStringList Boolean::toList() {
	newValue = QStringList{} << (getValue().toBool() ? "true" : "false");
	return newValue.toStringList();
}

}  // namespace vm::context::object
