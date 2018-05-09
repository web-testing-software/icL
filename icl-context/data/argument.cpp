#include "argument.h"

namespace vm::context::data {

Argument::Argument () {
	m_role = Role::Argument;
};



bool Argument::checkPrev (const Context *context) const {
	return
		context != nullptr &&
		(
		context->role () == Role::Argument ||
		(
			context->role () == Role::Assign &&
			context->prev () != nullptr      &&
			context->prev ()->role () == Role::Function
		)
		);
}

} // namespace
