#include "exists.h"

namespace vm::context::code::control::catch0 {

Exists::Exists () = default;

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
	return m_prev->role() != Role::Alternative;
}

} // namespace
