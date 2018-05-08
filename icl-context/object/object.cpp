#include "object.h"

namespace vm::context::object {

Object::Object () = default;



bool Object::checkPrev (const Context *context) const {
	return
		context == nullptr				 ||
		context->role () == Role::Assign ||
		( context->role () != Role::Exists && context->isResultative () );
}

} // namespace
