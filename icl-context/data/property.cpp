#include "property.h"

namespace vm::context::data {

Property::Property () {
	m_role = Role::Property;
};



bool Property::checkPrev (const Context *context) const {
	return context != nullptr && context->isResultative ();
}

bool Property::execute () const {

}

Context * Property::getNewContext () const {

}

Context * Property::getBeginContext () const {

}

Context * Property::getEndContext () const {

}

} // namespace
