#include "else.h"

namespace vm::context::code::control {

Else::Else () = default;



bool Else::checkPrev (const Context *context) const {
	return context != nullptr			  &&
		   context->role () == Role::Code &&
		   context->prev () != nullptr	  &&
		   context->prev ()->role () == Role::If;
}

bool Else::isExecuable () const {
	return m_next->role () == Role::Code;
}

} // namespace
