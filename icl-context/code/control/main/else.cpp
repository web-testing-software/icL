#include "else.h"

namespace vm::context::code::control {

Else::Else () = default;



bool Else::isExecuable () const {
	return m_next->role () == Role::Code;
}

} // namespace
