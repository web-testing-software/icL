#include "alternative.h"

namespace vm::context::data {

Alternative::Alternative () = default;



bool Alternative::isRightToLeft () const {
	return false;
}

bool Alternative::isExecuable () const {
	return true;
}

} // namespace
