#include "if.h"

namespace vm::context::code::control {

If::If () {
	m_role = Role::If;
};



bool If::checkPrev (const Context *context) const {
	return context == nullptr || context->role () == Role::Else;
}

bool If::isExecuable () const {
	return !expressionExecuted || result;
}

bool If::execute () const {

}

const Context *If::getBeginContext() const {

}

const Context *If::getEndContext() const {

}

} // namespace
