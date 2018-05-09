#include "property.h"

namespace vm::context::data {

Property::Property () {
	m_role = Role::Property;
};



bool Property::checkPrev (const Context *context) const {
	return context != nullptr && context->isResultative ();
}

bool Property::canBeAtEnd () const {
	return true;
}

bool Property::execute () {

}

Context * Property::getBeginContext () {
	return newContext != nullptr ? m_prev : this;
}

Context * Property::getEndContext () {
	return this;
}

} // namespace
