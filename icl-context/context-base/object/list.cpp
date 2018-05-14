#include "list.h"

namespace vm::context::object {



List::List(memory::DataState* container, const QString& varName)
	: Object(container, varName) {}

List::List(const QVariant& rvalue, bool readonly)
	: Object(rvalue, readonly) {}

List::List(const Object* const object)
	: Object(object) {}



QString List::getFirst() {
	QStringList value = getValue().toStringList();
	QString     ret;

	if (value.isEmpty()) {
		emit exception({-3, "Empty list cannot be casted to any types"});
	}
	else if (value.size() > 1) {
		emit exception(
		  {-4, "List with multiple values cannot be casted to any types"});
	}
	else {
		ret = value[0];
	}

	return ret;
}

memory::Type List::type() const {
	return memory::Type::List;
}



bool List::toBoolean() {
	QString value = getFirst();

	if (!value.isNull()) {
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
	}

	return false;
}

int List::toInt() {
	QString value = getFirst();

	if (!value.isNull()) {
		bool ok;
		int  res = value.toInt(&ok);

		if (ok) {
			newValue = res;
			return res;
		}
		else {
			sendCastFailed(value, QStringLiteral("Int"));
		}
	}

	return 0;
}

double List::toDouble() {
	QString value = getFirst();

	if (!value.isNull()) {
		bool ok;
		int  res = value.toDouble(&ok);

		if (ok) {
			newValue = res;
			return res;
		}
		else {
			sendCastFailed(value, QStringLiteral("Double"));
		}
	}

	return 0.0;
}

const QString List::toString() {
	QString value = getFirst();

	if (!value.isNull()) {
		newValue = value;
		return value;
	}

	return 0;
}

const QStringList List::toList() {
	newValue = getValue();
	return newValue.toStringList();
}

}  // namespace vm::context::object
