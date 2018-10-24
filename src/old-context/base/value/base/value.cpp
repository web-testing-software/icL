#include "value.h"

#include "bool.h"
#include "double.h"
#include "int.h"
#include "list.h"
#include "string.h"

#include <QDebug>
#include <QStringBuilder>

namespace icL::context::value {

Value::Value(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
    : Context(il)
    , container(container)
    , varName(varName)
    , valuetype(ValueType::L) {
	m_role = Role::Object;
}

Value::Value(memory::InterLevel * il, const QVariant & rvalue, bool readonly)
    : Context(il)
    , rvalue(rvalue)
    , readonly(readonly)
    , valuetype(ValueType::R) {
	m_role = Role::Object;
}

Value::Value(
  memory::InterLevel * il, const QString & getter, const QString & setter)
    : Context(il)
    , setter(setter)
    , getter(getter)
    , valuetype(ValueType::Js) {
	m_role = Role::Object;
}

Value::Value(memory::InterLevel * il, const Value * const object)
    : Context(il) {
	if (object->valuetype == ValueType::L) {
		container = object->container;
		varName   = object->varName;
	}
	else if (object->valuetype == ValueType::R) {
		rvalue   = object->rvalue;
		readonly = object->readonly;
	}
	else { /* object.value == Value.Js */
		getter = object->getter;
		setter = object->setter;
	}

	valuetype = object->valuetype;
	m_role    = Role::Object;
}

const QHash<QString, void (Value::*)(memory::ArgList &)> Value::methods =
  Value::initMethods();

const QHash<QString, void (Value::*)(memory::ArgList &)> Value::initMethods() {
	return {{{"IsRValue", &Value::runIsRValue},
	         {"IsReadOnly", &Value::runIsReadOnly},
	         {"IsLValue", &Value::runisLValue},
	         {"IsLink", &Value::runIsLink},
	         {"EnsureRValue", &Value::runEnsureRValue}}};
}



memory::Type Value::type() const {
	return memory::Type::Void;
}

QVariant Value::getValue() {
	if (valuetype == ValueType::R) {
		return rvalue;
	}
	else if (valuetype == ValueType::L) {
		return container->getValue(varName);
	}
	else { /* value == Value::Js */
		   //		newValue = il->server->runJS(getter);

		return newValue;
	}
}

void Value::setValue(const QVariant & value) {
	if (readonly) {
		// The Assign Block must check the readonly property
		qWarning() << "Value changed for readonly object!!!";
	}

	if (valuetype == ValueType::R) {
		rvalue = value;
	}
	else if (valuetype == ValueType::L) {
		container->setValue(varName, value);
	}
	else { /* this.value == Value.Js */
		   //		il->server->runJS(setter.arg(varToJsString(value)));
	}
}

const QString & Value::getVarName() const {
	return varName;
}

bool Value::isRValue() const {
	return valuetype == ValueType::R;
}

bool Value::isReadOnly() const {
	return valuetype == ValueType::R && readonly;
}

bool Value::isLValue() const {
	return valuetype == ValueType::L;
}

bool Value::isLink() const {
	return valuetype != ValueType::R || type() == memory::Type::Element;
}

Value * Value::ensureRValue() {
	return fromValue(getValue());
}

void Value::runIsRValue(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = isRValue();
		newContext = new Bool{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Value::runIsReadOnly(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = isReadOnly();
		newContext = new Bool{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Value::runisLValue(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = isLValue();
		newContext = new Bool{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Value::runIsLink(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = isLink();
		newContext = new Bool{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Value::runEnsureRValue(memory::ArgList & args) {
	if (args.length() == 0) {
		newContext = ensureRValue();
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void Value::runToBool(memory::ArgList & args) {
	if (args.length() == 0) {
		toBool();

		if (newValue.isNull()) {
			sendWrongCast("bool");
		}
	}
	else if (
	  args.length() == 1 && args[0].object->type() == memory::Type::Bool) {
		toBool();

		if (newValue.isNull()) {
			newValue = args[0].object->getValue();
		}
	}
	else {
		sendWrongArglist(args, "<> or <bool>");
		return;
	}

	newContext = new Bool{il, newValue, true};
}

void Value::runToInt(memory::ArgList & args) {
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

void Value::runToDouble(memory::ArgList & args) {
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

void Value::runToString(memory::ArgList & args) {
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

void Value::runToList(memory::ArgList & args) {
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

void Value::sendWrongCast(const QString & to) {
	il->vm->exception({-1, "Type " % memory::typeToString(type()) %
	                         " can not be casted to " % to});
}

void Value::sendCastFailed(const QString & value, const QString & type) {
	il->vm->exception(
	  {-3, R"(The string ")" % value % R"(" cannot be casted to )" % type});
}

void Value::runCast(const QString & name, memory::ArgList & args) {
	QStringRef type = name.midRef(2);

	if (type == "bool") {
		runToBool(args);
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
}

std::pair<bool, bool> Value::parseToBool(const QString & str) {
	bool ok = true;
	bool res;

	if (str == "true") {
		res = true;
	}
	else if (str == "false") {
		res = false;
	}
	else {
		ok = false;
	}

	if (ok) {
		return {res, true};
	}

	sendCastFailed(str, QStringLiteral("bool"));
	return {false, false};
}

std::pair<int, bool> Value::parseToInt(const QString & str) {
	bool ok;
	int  res = str.toInt(&ok);

	if (ok) {
		return {res, true};
	}

	sendCastFailed(str, QStringLiteral("Int"));
	return {0, false};
}

std::pair<double, bool> Value::parseToDouble(const QString & str) {
	bool ok;
	int  res = str.toDouble(&ok);

	if (ok) {
		return {res, true};
	}

	sendCastFailed(str, QStringLiteral("Double"));
	return {0.0, false};
};



bool Value::checkPrev(const Context * context) const {
	return context == nullptr || context->role() == Role::Assign ||
	       (context->role() != Role::Exists && context->isResultative());
}

bool Value::canBeAtEnd() const {
	return true;
}

Context * Value::runMethod(const QString & name, memory::ArgList & args) {

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

bool Value::isResultative() const {
	return true;
}

}  // namespace icL::context::value
