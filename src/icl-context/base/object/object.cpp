#include "object.h"

#include "boolean.h"
#include "double.h"
#include "int.h"
#include "list.h"
#include "string.h"

#include <QDebug>
#include <QStringBuilder>

namespace icL::context::object {

Object::Object(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Context(il)
	, container(container)
	, varName(varName)
	, value(Value::L) {
	m_role = Role::Object;
}

Object::Object(memory::InterLevel * il, const QVariant & rvalue, bool readonly)
	: Context(il)
	, rvalue(rvalue)
	, readonly(readonly)
	, value(Value::R) {
	m_role = Role::Object;
}

Object::Object(
  memory::InterLevel * il, const QString & getter, const QString & setter)
	: Context(il)
	, setter(setter)
	, getter(getter)
	, value(Value::Js) {
	m_role = Role::Object;
}

Object::Object(memory::InterLevel * il, const Object * const object)
	: Context(il) {
	if (object->value == Value::L) {
		container = object->container;
		varName   = object->varName;
	}
	else if (object->value == Value::R) {
		rvalue   = object->rvalue;
		readonly = object->readonly;
	}
	else { /* object.value == Value.Js */
		getter = object->getter;
		setter = object->setter;
	}

	value  = object->value;
	m_role = Role::Object;
}

const QHash<QString, void (Object::*)(memory::ArgList &)> Object::methods =
  Object::initMethods();

const QHash<QString, void (Object::*)(memory::ArgList &)>
Object::initMethods() {
	return {{{"IsRValue", &Object::runIsRValue},
			 {"IsReadOnly", &Object::runIsReadOnly},
			 {"IsLValue", &Object::runisLValue},
			 {"IsLink", &Object::runIsLink},
			 {"EnsureRValue", &Object::runEnsureRValue}}};
}



memory::Type Object::type() const {
	return memory::Type::Void;
}

QVariant Object::getValue() {
	if (value == Value::R) {
		return rvalue;
	}
	else if (value == Value::L) {
		return container->getValue(varName);
	}
	else { /* value == Value::Js */
		newValue = il->server->runJS(getter);

		return newValue;
	}
}

void Object::setValue(const QVariant & value) {
	if (readonly) {
		// The Assign Block must check the readonly property
		qWarning() << "Value changed for readonly object!!!";
	}

	if (this->value == Value::R) {
		rvalue = value;
	}
	else if (this->value == Value::L) {
		container->setValue(varName, value);
	}
	else { /* this.value == Value.Js */
		il->server->runJS(setter.arg(varToJsString(value)));
	}
}

const QString & Object::getVarName() const {
	return varName;
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
	return value != Value::R || type() == memory::Type::Element;
}

Object * Object::ensureRValue() {
	return fromValue(getValue());
}

void Object::runIsRValue(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = isRValue();
		newContext = new Boolean{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Object::runIsReadOnly(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = isReadOnly();
		newContext = new Boolean{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Object::runisLValue(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = isLValue();
		newContext = new Boolean{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Object::runIsLink(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = isLink();
		newContext = new Boolean{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Object::runEnsureRValue(memory::ArgList & args) {
	if (args.length() == 0) {
		newContext = ensureRValue();
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Object::runToBoolean(memory::ArgList & args) {
	if (args.length() == 0) {
		toBoolean();

		if (newValue.isNull()) {
			sendWrongCast("Boolean");
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

	newContext = new Boolean{il, newValue, true};
}

void Object::runToInt(memory::ArgList & args) {
	if (args.length() == 0) {
		toInt();

		if (newValue.isNull()) {
			sendWrongCast("Int");
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

	newContext = new Int{il, newValue, true};
}

void Object::runToDouble(memory::ArgList & args) {
	if (args.length() == 0) {
		toDouble();

		if (newValue.isNull()) {
			sendWrongCast("Double");
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

	newContext = new Double{il, newValue, true};
}

void Object::runToString(memory::ArgList & args) {
	if (args.length() == 0) {
		toString();

		if (newValue.isNull()) {
			sendWrongCast("String");
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

	newContext = new String{il, newValue, true};
}

void Object::runToList(memory::ArgList & args) {
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

	newContext = new List{il, newValue, true};
}

void Object::sendWrongCast(const QString & to) {
	il->vm->exception({-1, "Type " % memory::typeToString(type()) %
							 " can not be casted to " % to});
}

void Object::sendCastFailed(const QString & value, const QString & type) {
	il->vm->exception({-3, R"(The string ")" % value %
							 R"(" cannot be casted to )" % type});
}

void Object::runCast(const QString & name, memory::ArgList & args) {
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



bool Object::checkPrev(const Context * context) const {
	return context == nullptr || context->role() == Role::Assign ||
		   (context->role() != Role::Exists && context->isResultative());
}

bool Object::canBeAtEnd() const {
	return true;
}

Context * Object::runMethod(const QString & name, memory::ArgList & args) {

	if (name.mid(0, 2) == "To") {
		runCast(name, args);
	}
	else {
		auto it = methods.find(name);

		if (it != methods.end()) {
			(this->*it.value())(args);
		}
		else {
			Context::runMethod(name, args);
		}
	}

	return newContext;
}

bool Object::isResultative() const {
	return true;
}

}  // namespace icL::context::object
