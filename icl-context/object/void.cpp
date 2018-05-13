#include "void.h"

namespace vm::context::object {

Void::Void()
	: Object(QVariant(), true) {}

bool Void::toBoolean() {
	return false;
}

int Void::toInt() {
	return 0;
}

double Void::toDouble() {
	return 0.0;
}

const QString Void::toString() {
	return QString{};
}

const QStringList Void::toList() {
	return QStringList{};
};

}  // namespace vm::context::object
