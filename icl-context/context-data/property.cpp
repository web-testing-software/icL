#include "property.h"

namespace icL::context::data {

Property::Property(const QString & name)
	: name(name) {
	m_role = Role::Property;
};



bool Property::checkPrev(const Context * context) const {
	return context != nullptr && context->isResultative();
}

bool Property::canBeAtEnd() const {
	return true;
}

bool Property::execute() {
	newContext = m_prev->runProperty(name);

	return true;
}

Context * Property::getBeginContext() {
	return m_prev;
}

Context * Property::getEndContext() {
	return this;
}

bool Property::isResultative() const {
	return true;
}

}  // namespace icL::context::data
