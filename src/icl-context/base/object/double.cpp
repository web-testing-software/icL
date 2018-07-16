#include "double.h"

namespace icL::context::object {



Double::Double(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Value(il, container, varName) {}

Double::Double(memory::InterLevel * il, const QVariant & rvalue, bool readonly)
	: Value(il, rvalue, readonly) {}

Double::Double(
  memory::InterLevel * il, const QString & getter, const QString & setter)
	: Value(il, getter, setter) {}

Double::Double(memory::InterLevel * il, const Value * const object)
	: Value(il, object) {}

Context * Double::runMethod(const QString & name, memory::ArgList & args) {
	return Value::runMethod(name, args);
}

memory::Type Double::type() const {
	return memory::Type::Double;
}

bool Double::toBool() {
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
