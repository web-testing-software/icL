#include <utility>

#include "context.h"


namespace vm::context {

Context::Context () = default;

Context * Context::getNewContext () {
	return nullptr;
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
	emit exception(-7, "No such property: " + name);
}

void Context::runMethod (const QString &name) {
	emit exception(-7, "No such method: " + name);
}

bool Context::isResultative () {
	return
		role == Role::Object ||
		role == Role::Property ||
		role == Role::Method ||
		role == Role::Isolated ||
		role == Role::Function ||
		role == Role::Exists;
}

void Context::repeat (QString *str, int begin, int end, std::function <void ( QVariant& )> func) {
	emit interrupt (str, begin, end, std::move (func) );
}

} // namespace
