#include "int.h"

namespace vm::context::object {



Int::Int(memory::DataState* container, const QString& varName)
	: Object(container, varName) {}

Int::Int(const QVariant& rvalue, bool readonly)
	: Object(rvalue, readonly) {}

Int::Int(const QString& getter, const QString& setter)
	: Object(getter, setter) {}

Int::Int(const Object* const object)
	: Object(object) {}



memory::Type Int::type() const {
	return memory::Type::Int;
}


bool Int::toBoolean() {
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

}  // namespace vm::context::object
