#include "forany.h"

namespace vm::context::code {

ForAny::ForAny () = default;



bool ForAny::checkPrev (const Context *context) const {
	return
		context == nullptr				 ||
		context->role () == Role::Assign ||
		context->isResultative ();
}

bool ForAny::isExecuable () const {
	return true;
}

} // namespace
