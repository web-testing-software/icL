#include "alternative.h"

namespace vm::context::data {

Alternative::Alternative () = default;



bool Alternative::checkPrev (const Context *context) const {
	return context != nullptr && context->role () == Role::Exists;
}

bool Alternative::isRightToLeft () const {
	return false;
}

bool Alternative::isExecuable () const {
	return true;
}

} // namespace
