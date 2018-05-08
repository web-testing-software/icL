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

bool Alternative::execute () const {

}

Context * Alternative::getNewContext () const {

}

Context * Alternative::getBeginContext () const {

}

Context * Alternative::getEndContext () const {

}

} // namespace
