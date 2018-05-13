#include "context.h"

#include <object/boolean.h>
#include <object/double.h>
#include <object/element.h>
#include <object/int.h>
#include <object/list.h>
#include <object/object.h>
#include <object/string.h>
#include <object/void.h>

#include <utility>


namespace vm::context {

Context::Context() = default;

Context* Context::getNewContext() const {
	return newContext;
}

Context* Context::getBeginContext() {
	return nullptr;
}

Context* Context::getEndContext() {
	return nullptr;
}

bool Context::isRightToLeft() const {
	return true;
}

bool Context::isExecuable() const {
	return false;
}

bool Context::execute() {
	return true;
}

bool Context::hasValue() const {
	return false;
}

Context* Context::runProperty(const QString& name) {
	emit exception({-7, "No such property: " + name});

	return nullptr;
}

Context* Context::runMethod(const QString& name, memory::ArgList& args) {
	Q_UNUSED(args);
	emit exception({-7, "No such method: " + name});

	return nullptr;
}

bool Context::isResultative() const {
	return false;
}

bool Context::isComplex() const {
	return false;
}

Context* Context::fromValue(const QVariant& value) {
	object::Object* ret;
	memory::Type    type = memory::variantTypeToType(value.type());

	switch (type) {
	case memory::Type::Boolean:
		ret = new object::Boolean{value, true};
		break;

	case memory::Type::Int:
		ret = new object::Int{value, true};
		break;

	case memory::Type::Double:
		ret = new object::Double{value, true};
		break;

	case memory::Type::String:
		ret = new object::String{value, true};
		break;

	case memory::Type::List:
		ret = new object::List{value, true};
		break;

	case memory::Type::Element:
		ret = new object::Element{value, true};
		break;

	case memory::Type::Void:
		ret = new object::Void;
		break;
	}

	return ret;
}

Context* Context::getFirst() {
	Context* it = this;

	while (it->m_prev != nullptr) {
		it = it->m_prev;
	}

	return it;
}

Context* Context::getLast() {
	Context* it = this;

	while (it->m_next != nullptr) {
		it = it->m_next;
	}

	return it;
}

void Context::sendWrongArglist(
  memory::ArgList& args, const QString& expected) {
	QStringList types;

	for (auto arg : args) {
		types.append(memory::typeToString(arg.object->type()));
	}

	emit exception({-203, "Wrong arglist: <" % types.join(", ") %
							">, expected " % expected});
}

void Context::repeatException(memory::Exception exc) {
	emit exception(std::move(exc));
}

void Context::repeat(
  memory::FunctionCall run, std::function<void(memory::Return&)> feedback) {
	emit interrupt(std::move(run), std::move(feedback));
}

Context* Context::next() const {
	return m_next;
}

Context* Context::prev() const {
	return m_prev;
}

Role Context::role() const {
	return m_role;
}

}  // namespace vm::context
