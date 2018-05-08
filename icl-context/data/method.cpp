#include "method.h"

namespace vm::context::data {

Method::Method () {
	m_role = Role::Method;
};



bool Method::checkPrev (const Context *context) const {
	return context != nullptr && context->isResultative ();
}

bool Method::execute () const {

}

Context * Method::getNewContext () const {

}

Context * Method::getBeginContext () const {

}

Context * Method::getEndContext () const {

}

} // namespace
