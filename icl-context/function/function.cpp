#include "function.h"

namespace vm::context::function {

Function::Function () {
	m_role = Role::Function;
};



bool Function::checkPrev (const Context *context) const {
	return
		context == nullptr                    ||
		context->role () == Role::Alternative ||
		context->role () == Role::Assign      ||
		context->isResultative ();
}

bool Function::isExecuable () const {
	return true;
}

} // namespace
