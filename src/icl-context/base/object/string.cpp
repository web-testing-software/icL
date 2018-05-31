#include "string.h"

namespace icL::context::object {



String::String(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Object(il, container, varName) {}

String::String(memory::InterLevel * il, const QVariant & rvalue, bool readonly)
	: Object(il, rvalue, readonly) {}

String::String(
  memory::InterLevel * il, const QString & getter, const QString & setter)
	: Object(il, getter, setter) {}

String::String(memory::InterLevel * il, const Object * const object)
	: Object(il, object) {}

Context * String::runMethod(const QString & name, memory::ArgList & args) {
	return Object::runMethod(name, args);
}



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
