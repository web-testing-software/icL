#include "int.h"

namespace old::context::value {



Int::Int(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
    : Value(il, container, varName) {}

Int::Int(memory::InterLevel * il, const QVariant & rvalue, bool readonly)
    : Value(il, rvalue, readonly) {}

Int::Int(
  memory::InterLevel * il, const QString & getter, const QString & setter)
    : Value(il, getter, setter) {}

Int::Int(memory::InterLevel * il, const Value * const object)
    : Value(il, object) {}

Context * Int::runMethod(const QString & name, memory::ArgList & args) {
	return Value::runMethod(name, args);
}



memory::Type Int::type() const {
	return memory::Type::Int;
}


bool Int::toBool() {
	newValue = getValue().toInt() != 0;
	return newValue.toBool();
}

int Int::toInt() {
	newValue = getValue();
	return newValue.toInt();
}

double Int::toDouble() {
	newValue = static_cast<double>(getValue().toInt());
	return newValue.toDouble();
}

const QString Int::toString() {
	newValue = QString::number(getValue().toInt());
	return newValue.toString();
}

const QStringList Int::toList() {
	newValue = QStringList{} << QString::number(getValue().toInt());
	return newValue.toStringList();
}

}  // namespace old::context::value
