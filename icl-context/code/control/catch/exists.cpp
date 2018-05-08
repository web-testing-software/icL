#include "exists.h"

namespace vm::context::code::control::catch0 {

Exists::Exists () = default;

int Exists::signal () const {
	return m_signal;
}

// Context interface

bool Exists::isExecuable () const {
	return true;
}

} // namespace
