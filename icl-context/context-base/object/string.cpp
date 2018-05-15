#include "string.h"

namespace icL::context::object {



String::String(memory::DataState * container, const QString & varName)
	: Object(container, varName) {}

String::String(const QVariant & rvalue, bool readonly)
	: Object(rvalue, readonly) {}

String::String(const QString & getter, const QString & setter)
	: Object(getter, setter) {}

String::String(const Object * const object)
	: Object(object) {}



memory::Type String::type() const {
	return memory::Type::String;
}


bool String::toBoolean() {
	QString value = getValue().toString();

	bool ok = true;
	bool res;

	if (value == "true") {
		res = true;
	}
	else if (value == "false") {
		res = false;
	}
	else {
		ok = false;
	}

	if (ok) {
		newValue = res;
		return res;
	}
	else {
		sendCastFailed(value, QStringLiteral("Boolean"));
	}

	return false;
}

int String::toInt() {
	QString value = getValue().toString();

	bool ok;
	int  res = value.toInt(&ok);

	if (ok) {
		newValue = res;
		return res;
	}
	else {
		sendCastFailed(value, QStringLiteral("Int"));
	}

	return 0;
}

double String::toDouble() {
	QString value = getValue().toString();

	bool ok;
	int  res = value.toDouble(&ok);

	if (ok) {
		newValue = res;
		return res;
	}
	else {
		sendCastFailed(value, QStringLiteral("Double"));
	}

	return 0.0;
}

const QString String::toString() {
	newValue = getValue();
	return newValue.toString();
}

const QStringList String::toList() {
	newValue = QStringList{} << getValue().toString();
	return newValue.toStringList();
}

}  // namespace icL::context::object
