#include "code.h"

namespace vm::context::code {

Code::Code () = default;



bool Code::checkPrev (const Context *context) const {
	return
		context != nullptr &&
		(
		context->role () == Role::Else     ||
		context->role () == Role::Slot     ||
		context->role () == Role::Argument ||
		(
			context->role () == Role::Assign &&
			context->prev () != nullptr      &&
			context->prev ()->role () == Role::Function
		)                                  ||
		context->isResultative ()
		);
}

bool Code::canBeAtEnd () const {
	return true;
}

bool Code::isExecuable () const {
	return m_prev->role () == Role::Object;
}

Context * Code::getBeginContext () {
	return this;
}

Context * Code::getEndContext () {
	return this;
}

} // namespace
