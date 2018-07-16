#include "void.h"

namespace icL::context::object {

Void::Void(memory::InterLevel * il)
	: Value(il, QVariant(), true) {}

Void::Void(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Value(il, container, varName) {}

Void::Void(
  memory::InterLevel * il, const QString & getter, const QString & setter)
	: Value(il, getter, setter) {}

Context * Void::runProperty(
  [[maybe_unused]] Prefix prefix, [[maybe_unused]] const QString & name) {
	return nullptr;
}

Context * Void::runMethod(
  [[maybe_unused]] const QString &   name,
  [[maybe_unused]] memory::ArgList & args) {
	return nullptr;
}


bool Void::toBool() {
	newValue = false;
	return false;
}

int Void::toInt() {
	newValue = 0;
	return 0;
}

double Void::toDouble() {
	newValue = 0.0;
	return 0.0;
}

const QString Void::toString() {
	newValue = "";
	return QString{};
}

const QStringList Void::toList() {
	newValue = QStringList{};
	return QStringList{};
};

}  // namespace icL::context::object
