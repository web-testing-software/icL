#include "property.h"

namespace vm::context::data {

Property::Property () = default;



bool Property::checkPrev (const Context *context) const {
	return context != nullptr && context->isResultative ();
}

} // namespace
