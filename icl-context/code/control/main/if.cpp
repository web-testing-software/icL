#include "if.h"

namespace vm::context::code::control {

If::If () = default;



bool If::isExecuable () {
	return !expressionExecuted || result;
}

} // namespace
