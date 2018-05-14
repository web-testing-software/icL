#include "double.h"

namespace vm::context::object {



Double::Double(memory::DataState* container, const QString& varName)
	: Object(container, varName) {}

Double::Double(const QVariant& rvalue, bool readonly)
	: Object(rvalue, readonly) {}

Double::Double(const QString& getter, const QString& setter)
	: Object(getter, setter) {}

Double::Double(const Object* const object)
	: Object(object) {}

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

}  // namespace vm::context::object
