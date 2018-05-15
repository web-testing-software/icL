#include "void.h"

namespace icL::context::object {

Void::Void()
	: Object(QVariant(), true) {}

Void::Void(const QString & getter, const QString & setter)
	: Object(getter, setter) {}


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
