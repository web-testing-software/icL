#include "method.h"

namespace vm::context::data {

Method::Method () {
	m_role = Role::Method;
};



bool Method::checkPrev (const Context *context) const {
	return context != nullptr && context->isResultative ();
}

bool Method::canBeAtEnd () const {
	return true;
}

bool Method::execute () const {

}

Context * Method::getBeginContext () {
	return newContext != nullptr ? m_prev : this;
}

Context * Method::getEndContext () {
	return this;
}

} // namespace
