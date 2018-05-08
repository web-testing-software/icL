#include "method.h"

namespace vm::context::data {

Method::Method () = default;



bool Method::checkPrev (const Context *context) const {
	return context != nullptr && context->isResultative ();
}

} // namespace
