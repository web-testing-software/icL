#include "double.h"

namespace icL::context::object {



Double::Double(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Object(il, container, varName) {}

Double::Double(memory::InterLevel * il, const QVariant & rvalue, bool readonly)
	: Object(il, rvalue, readonly) {}

Double::Double(
  memory::InterLevel * il, const QString & getter, const QString & setter)
	: Object(il, getter, setter) {}

Double::Double(memory::InterLevel * il, const Object * const object)
	: Object(il, object) {}

Context * Double::runMethod(const QString & name, memory::ArgList & args) {
	return Object::runMethod(name, args);
}

memory::Type Double::type() const {
	return memory::Type::Double;
}

bool Double::toBoolean() {
	newValue = getValue().toDouble() != 0.0;
	return newValue.toBool();
}

int Double::toInt() {
	newValue = static_cast<int>(getValue().toDouble());
	return newValue.toInt();
}

double Double::toDouble() {
	newValue = getValue();
	return newValue.toDouble();
}

const QString Double::toString() {
	newValue = QString::number(getValue().toDouble());
	return newValue.toString();
}

const QStringList Double::toList() {
	newValue = QStringList{} << QString::number(getValue().toDouble());
	return newValue.toStringList();
}

}  // namespace icL::context::object
