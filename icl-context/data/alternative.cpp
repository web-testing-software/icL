#include "alternative.h"

namespace vm::context::data {

Alternative::Alternative () {
	m_role = Role::Alternative;
};



bool Alternative::checkPrev (const Context *context) const {
	return context != nullptr && context->role () == Role::Exists;
}

bool Alternative::isRightToLeft () const {
	return false;
}

bool Alternative::isExecuable () const {
	return true;
}

bool Alternative::execute () {

}

Context * Alternative::getBeginContext () {
	return theLeftOperandIsOk ? this : m_prev;
}

Context * Alternative::getEndContext () {
	return theLeftOperandIsOk ? m_next : this;
}

} // namespace