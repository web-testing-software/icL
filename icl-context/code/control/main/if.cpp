#include "if.h"

namespace vm::context::code::control {

If::If () = default;



bool If::checkPrev (const Context *context) const {
	return context == nullptr || context->role () == Role::Else;
}

bool If::isExecuable () const {
	return !expressionExecuted || result;
}

} // namespace
