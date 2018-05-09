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

const Context *Function::getBeginContext() const {

}

const Context *Function::getEndContext() const {

}

} // namespace
