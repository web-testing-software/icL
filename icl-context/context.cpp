#include <utility>

#include "context.h"


namespace vm::context {

Context::Context () = default;

Context * Context::getNewContext () {
	return newContext;
}

Context * Context::getBeginContext () {
	return nullptr;
}

Context * Context::getEndContext () {
	return nullptr;
}

bool Context::isRightToLeft () {
	return true;
}

bool Context::isExecuable () {
	return false;
}

bool Context::execute () {
	return true;
}

bool Context::hasValue () {
	return false;
}

void Context::runProperty (const QString &name) {
	emit exception (-7, "No such property: " + name);
}

void Context::runMethod (const QString &name) {
	emit exception (-7, "No such method: " + name);
}

bool Context::isResultative () {
	return
		m_role == Role::Object   ||
		m_role == Role::Property ||
		m_role == Role::Method   ||
		m_role == Role::Isolated ||
		m_role == Role::Function ||
		m_role == Role::Exists;
}

void Context::repeatException (int code, const QString &message) {
	emit exception (code, message);
}

void Context::repeat (QString *str, int begin, int end, std::function <void ( QVariant& )> func) {
	emit interrupt (str, begin, end, std::move (func) );
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
