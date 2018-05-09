#include "function.h"

namespace vm::context::function {

Function::Function () {
	m_role = Role::Function;
};



bool Function::checkPrev (const Context *context) const {
	return
		context == nullptr ||
		(
		!newFunction &&
		(
			context->role () == Role::Alternative ||
			context->role () == Role::Assign      ||
			context->isResultative ()
		)
		);
}

bool Function::canBeAtEnd () const {
	return !newFunction;
}

bool Function::isExecuable () const {
	return true;
}

bool Function::execute () const {

}

Context * Function::getBeginContext () {
	return this;
}

Context * Function::getEndContext () {
	if (newFunction) {
		return getLast();
	}

	Context *it = m_next;

	if (it == nullptr || it->role() != Role::Object) {
		return this;
	}

	while (it->next() != nullptr && it->role() == Role::Object) {
		it = it->next();
	}

	return it;
}

} // namespace
