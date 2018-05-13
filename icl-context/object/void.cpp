#include "void.h"

namespace vm::context::object {

Void::Void()
	: Object(QVariant(), true) {}

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
	newValue = QString{};
	return QString{};
}

const QStringList Void::toList() {
	newValue = QStringList{};
	return QStringList{};
};

}  // namespace vm::context::object
