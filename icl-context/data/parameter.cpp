#include "parameter.h"

namespace vm::context::data {

Parameter::Parameter(const QString& name, memory::Type type)
	: m_name(name)
	, m_type(type) {
	m_role = Role::Argument;
}

memory::Type Parameter::type() const {
	return m_type;
}

const QString& Parameter::name() const {
	return m_name;
};



bool Parameter::checkPrev(const Context* context) const {
	return context != nullptr &&
		   (context->role() == Role::Argument ||
			(context->role() == Role::Assign && context->prev() != nullptr &&
			 context->prev()->role() == Role::Function));
}

}  // namespace vm::context::data
