#include "object.h"

namespace vm::context::object {

Object::Object () {
	m_role = Role::Object;
};



bool Object::checkPrev (const Context *context) const {
	return
		context == nullptr				 ||
		context->role () == Role::Assign ||
		( context->role () != Role::Exists && context->isResultative () );
}

} // namespace
