#include "if.h"

namespace vm::context::code::control {

If::If () = default;



bool If::isExecuable () const {
	return !expressionExecuted || result;
}

} // namespace
