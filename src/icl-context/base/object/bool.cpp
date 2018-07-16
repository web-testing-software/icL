#include "bool.h"

namespace icL::context::object {



Bool::Bool(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Value(il, container, varName) {}

Bool::Bool(
  memory::InterLevel * il, const QVariant & rvalue, bool readonly)
	: Value(il, rvalue, readonly) {}

Bool::Bool(
  memory::InterLevel * il, const QString & getter, const QString & setter)
	: Value(il, getter, setter) {}

Bool::Bool(memory::InterLevel * il, const Value * const object)
	: Value(il, object) {}

Context * Bool::runMethod(const QString & name, memory::ArgList & args) {
	return Value::runMethod(name, args);
}

memory::Type Bool::type() const {
	return memory::Type::Bool;
}

bool Bool::toBool() {
	newValue = getValue();
	return newValue.toBool();
}

int Bool::toInt() {
	newValue = getValue().toBool() ? 1 : 0;
	return newValue.toInt();
}

double Bool::toDouble() {
	newValue = getValue().toBool() ? 1.0 : 0.0;
	return newValue.toDouble();
}

const QString Bool::toString() {
	newValue = getValue().toBool() ? "true" : "false";
	return newValue.toString();
}

const QStringList Bool::toList() {
	newValue = QStringList{} << (getValue().toBool() ? "true" : "false");
	return newValue.toStringList();
}

}  // namespace icL::context::object
