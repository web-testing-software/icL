#include "forany.h"

namespace vm::context::code {

ForAny::ForAny () {
	m_role = Role::ForAny;
};



bool ForAny::checkPrev (const Context *context) const {
	return
		context == nullptr               ||
		context->role () == Role::Assign ||
		context->isResultative ();
}

bool ForAny::isExecuable () const {
	return true;
}

bool ForAny::execute () {

}

Context * ForAny::getBeginContext () {
	return this;
}

Context * ForAny::getEndContext () {
	return this;
}

} // namespace