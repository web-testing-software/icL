#include "code.h"

namespace vm::context::code {

Code::Code () = default;



bool Code::isExecuable () {
	return m_prev->role () == Role::Object;
}

} // namespace
