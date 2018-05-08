#include "alternative.h"

namespace vm::context::data {

Alternative::Alternative () = default;



bool Alternative::isRightToLeft () {
	return false;
}

bool Alternative::isExecuable () {
	return true;
}

} // namespace
