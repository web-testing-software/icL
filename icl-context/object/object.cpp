#include "object.h"

#include <QDebug>

namespace vm::context::object {

Object::Object(memory::DataState* container, const QString& varName)
	: container(container)
	, varName(varName)
	, value(Value::L) {
	m_role = Role::Object;
}

Object::Object(const QVariant& rvalue, bool readonly)
	: rvalue(rvalue)
	, readonly(readonly)
	, value(Value::R) {
	m_role = Role::Object;
}

Object::Object(const Object* const object) {
	if (object->value == Value::L) {
		container = object->container;
		varName   = object->varName;
	}
	else {
		rvalue   = object->rvalue;
		readonly = object->readonly;
	}

	value  = object->value;
	m_role = Role::Object;
}

memory::Type Object::type() const {
	if (value == Value::R) {
		return memory::variantTypeToType(rvalue.type());
	}

	return container->getType(varName);
}

bool Object::isRValue() const {
	return value == Value::R;
}

bool Object::isReadOnly() const {
	return value == Value::R && readonly;
}

bool Object::isLValue() const {
	return value == Value::L;
}

bool Object::isLink() const {
	return value == Value::L || type() == memory::Type::Element;
}

QVariant Object::getValue() const {
	return value == Value::R ? rvalue : container->getValue(varName);
}

void Object::setValue(const QVariant& value) {
	if (readonly) {
		// The Assign Block must check the readonly property
		qWarning() << "Value changed for readonly object!!!";
	}

	if (this->value == Value::R) {
		rvalue = value;
	}
	else {
		container->setValue(varName, value);
	}
}

const QString& Object::getVarName() const {
	return varName;
}

void Object::runToBoolean(memory::ArgList& args) {
	if (args.length() == 0) {
		toBoolean();

		if (newValue.isNull()) {
			sendWrongCast("List");
		}
	}
	else if (
	  args.length() == 1 && args[0].object->type() == memory::Type::Boolean) {
		toBoolean();

		if (newValue.isNull()) {
			newValue = args[0].object->getValue();
		}
	}
	else {
		sendWrongArglist(args, "<> or <Boolean>");
		return;
	}

	newContext = fromValue(newValue);
}

void Object::runToInt(memory::ArgList& args) {
	if (args.length() == 0) {
		toInt();

		if (newValue.isNull()) {
			sendWrongCast("List");
		}
	}
	else if (
	  args.length() == 1 && args[0].object->type() == memory::Type::Int) {
		toInt();

		if (newValue.isNull()) {
			newValue = args[0].object->getValue();
		}
	}
	else {
		sendWrongArglist(args, "<> or <Int>");
		return;
	}

	newContext = fromValue(newValue);
}

void Object::runToDouble(memory::ArgList& args) {
	if (args.length() == 0) {
		toDouble();

		if (newValue.isNull()) {
			sendWrongCast("List");
		}
	}
	else if (
	  args.length() == 1 && args[0].object->type() == memory::Type::Double) {
		toDouble();

		if (newValue.isNull()) {
			newValue = args[0].object->getValue();
		}
	}
	else {
		sendWrongArglist(args, "<> or <Double>");
		return;
	}

	newContext = fromValue(newValue);
}

void Object::runToString(memory::ArgList& args) {
	if (args.length() == 0) {
		toString();

		if (newValue.isNull()) {
			sendWrongCast("List");
		}
	}
	else if (
	  args.length() == 1 && args[0].object->type() == memory::Type::String) {
		toString();

		if (newValue.isNull()) {
			newValue = args[0].object->getValue();
		}
	}
	else {
		sendWrongArglist(args, "<> or <String>");
		return;
	}

	newContext = fromValue(newValue);
}

void Object::runToList(memory::ArgList& args) {
	if (args.length() == 0) {
		toList();

		if (newValue.isNull()) {
			sendWrongCast("List");
		}
	}
	else if (
	  args.length() == 1 && args[0].object->type() == memory::Type::List) {
		toList();

		if (newValue.isNull()) {
			newValue = args[0].object->getValue();
		}
	}
	else {
		sendWrongArglist(args, "<> or <List>");
		return;
	}

	newContext = fromValue(newValue);
}

void Object::sendWrongCast(const QString& to) {
	emit exception({-1, "Type " % memory::typeToString(type()) %
						  " can not be casted to " % to});
}

void Object::runCast(const QString& name, memory::ArgList& args) {
	QStringRef type = name.midRef(2);

	if (type == "Boolean") {
		runToBoolean(args);
	}
	else if (type == "Int") {
		runToInt(args);
	}
	else if (type == "Double") {
		runToDouble(args);
	}
	else if (type == "String") {
		runToString(args);
	}
	else if (type == "List") {
		runToList(args);
	}
};



bool Object::checkPrev(const Context* context) const {
	return context == nullptr || context->role() == Role::Assign ||
		   (context->role() != Role::Exists && context->isResultative());
}

bool Object::canBeAtEnd() const {
	return true;
}

bool Object::isResultative() const {
	return true;
}

}  // namespace vm::context::object
