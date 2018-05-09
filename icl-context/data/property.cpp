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

bool Property::execute () const {

}

const Context *Property::getBeginContext() const {

}

const Context *Property::getEndContext() const {

}

} // namespace
