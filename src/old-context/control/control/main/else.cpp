#include "else.h"

namespace old::context::code::control {

Else::Else(memory::InterLevel * il)
    : Control(il, memory::CodeFragment()) {
	m_role = Role::Else;
};



bool Else::checkPrev(const Context * context) const {
	return context != nullptr && context->role() == Role::Code &&
	       context->prev() != nullptr && context->prev()->role() == Role::If;
}

bool Else::isExecutable() const {
	return m_next->role() == Role::Code;
}

memory::StepType::Value Else::execute() {
	return m_next->execute();
}

Context * Else::getBeginContext() {
	return getFirst();
}

Context * Else::getEndContext() {
	return getLast();
}

}  // namespace old::context::code::control
