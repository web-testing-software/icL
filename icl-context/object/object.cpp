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
