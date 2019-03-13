#include "alternative.h"

namespace old::context::data {

Alternative::Alternative(memory::InterLevel * il)
    : Data(il) {
	m_role = Role::Alternative;
};



bool Alternative::checkPrev(const Context * context) const {
	return context != nullptr && context->role() == Role::Exists;
}

bool Alternative::isRightToLeft() const {
	return false;
}

bool Alternative::isExecutable() const {
	return true;
}

memory::StepType::Value Alternative::execute() {
	theLeftOperandIsOk = m_prev->hasValue();

	return memory::StepType::MiniStep;
}

Context * Alternative::getBeginContext() {
	return theLeftOperandIsOk ? this : m_prev;
}

Context * Alternative::getEndContext() {
	return theLeftOperandIsOk ? m_next : this;
}

}  // namespace old::context::data
