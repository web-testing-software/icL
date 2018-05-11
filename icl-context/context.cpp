#include <utility>

#include <object/object.h>

#include <code/control/catch/exists.h>

#include "context.h"


namespace vm::context {

Context::Context () = default;

Context * Context::getNewContext () const {
	return newContext;
}

Context * Context::getBeginContext () {
	return nullptr;
}

Context * Context::getEndContext () {
	return nullptr;
}

bool Context::isRightToLeft () const {
	return true;
}

bool Context::isExecuable () const {
	return false;
}

bool Context::execute () {
	return true;
}

bool Context::hasValue () const {
	return false;
}

Context * Context::runProperty (const QString &name) {
	emit exception ({ -7, "No such property: " + name });

	return nullptr;
}

Context * Context::runMethod (const QString &name, memory::ParamList &params) {
	Q_UNUSED (params);
	emit exception ({ -7, "No such method: " + name });

	return nullptr;
}

bool Context::isResultative () const {
	return
		m_role == Role::Object   ||
		m_role == Role::Property ||
		m_role == Role::Method   ||
		m_role == Role::ForAny   ||
		m_role == Role::Function ||
		(
		m_role == Role::Exists &&
		!dynamic_cast <const code::control::catch0::Exists *> ( this )->getIsEmiter ()
		);
}

Context * Context::fromValue (QVariant &value) {
	// TODO: Write this function where class object will be ready

//	object::Object *ret;
//	memory::Type type = memory::variantTypeToType(value.type());
}

Context * Context::getFirst () {
	Context *it = this;

	while (it->m_prev != nullptr) {
		it = it->m_prev;
	}

	return it;
}

Context * Context::getLast () {
	Context *it = this;

	while (it->m_next != nullptr) {
		it = it->m_next;
	}

	return it;
}

void Context::repeatException (memory::Exception exc) {
	emit exception (std::move (exc) );
}

void Context::repeat (memory::FunctionCall run, std::function <void ( memory::Return& )> feedback) {
	emit interrupt (std::move (run), std::move (feedback) );
}

Context * Context::next () const {
	return m_next;
}

Context * Context::prev () const {
	return m_prev;
}

Role Context::role () const {
	return m_role;
}

} // namespace
