#include "boolean.h"

namespace icL::context::object {



Boolean::Boolean(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Object(il, container, varName) {}

Boolean::Boolean(
  memory::InterLevel * il, const QVariant & rvalue, bool readonly)
	: Object(il, rvalue, readonly) {}

Boolean::Boolean(
  memory::InterLevel * il, const QString & getter, const QString & setter)
	: Object(il, getter, setter) {}

Boolean::Boolean(memory::InterLevel * il, const Object * const object)
	: Object(il, object) {}

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

}  // namespace icL::context::object
