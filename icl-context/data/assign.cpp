#include "assign.h"

namespace vm::context::data {

Assign::Assign () {
	m_role = Role::Assign;
};



bool Assign::checkPrev (const Context *context) const {
	return
		context != nullptr &&
		( context->role () == Role::Object || context->role () == Role::Function ) &&
		( context->prev () == nullptr || context->prev ()->role () == Role::Assign );
}

bool Assign::isExecuable () const {
	return true;
}

bool Assign::execute () const {

}

Context *Assign::getBeginContext() {

}

Context *Assign::getEndContext() {

}

} // namespace
