#include "exists.h"

namespace vm::context::code::control::catch0 {

Exists::Exists () {
	m_role = Role::Exists;
};

int Exists::signal () const {
	return m_signal;
}

bool Exists::checkPrev (const Context *context) const {
	return context == nullptr ||
		   context->role () == Role::Alternative ||
		   context->role () == Role::Assign;
}

// Context interface

bool Exists::isExecuable () const {
	return m_prev->role () != Role::Alternative;
}

bool Exists::execute () {

}

Context * Exists::getBeginContext () {
	return this;
}

Context * Exists::getEndContext () {
	return this;
}

} // namespace
