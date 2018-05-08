#include "assign.h"

namespace vm::context::data {

Assign::Assign () = default;



bool Assign::isExecuable () const {
	return true;
}

} // namespace
