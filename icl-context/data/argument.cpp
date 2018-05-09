#include "argument.h"

namespace vm::context::data {

Argument::Argument () {
	m_role = Role::Argument;
}

memory::Type Argument::type () const {
	return m_type;
}

const QString& Argument::name () const {
	return m_name;
};



bool Argument::checkPrev (const Context *context) const {
	return
		context != nullptr &&
		(
		context->role () == Role::Argument ||
		(
			context->role () == Role::Assign &&
			context->prev () != nullptr      &&
			context->prev ()->role () == Role::Function
		)
		);
}

} // namespace
