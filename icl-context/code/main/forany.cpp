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

bool ForAny::execute () const {

}

Context * ForAny::getBeginContext () const {

}

Context * ForAny::getEndContext () const {

}

} // namespace
