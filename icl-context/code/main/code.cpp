#include "code.h"

namespace vm::context::code {

Code::Code () = default;



bool Code::isExecuable () const {
	return m_prev->role () == Role::Object;
}

} // namespace
