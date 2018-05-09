#include "else.h"

namespace vm::context::code::control {

Else::Else () {
	m_role = Role::Else;
};



bool Else::checkPrev (const Context *context) const {
	return context != nullptr             &&
		   context->role () == Role::Code &&
		   context->prev () != nullptr    &&
		   context->prev ()->role () == Role::If;
}

bool Else::isExecuable () const {
	return m_next->role () == Role::Code;
}

bool Else::execute () {

}

Context * Else::getBeginContext () {
	return getFirst ();
}

Context * Else::getEndContext () {
	return getLast ();
}

} // namespace
