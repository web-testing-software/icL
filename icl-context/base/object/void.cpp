#include "void.h"

namespace icL::context::object {

Void::Void(memory::InterLevel * il)
	: Object(il, QVariant(), true) {}

Void::Void(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Object(il, container, varName) {}

Void::Void(
  memory::InterLevel * il, const QString & getter, const QString & setter)
	: Object(il, getter, setter) {}


bool Void::toBoolean() {
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
