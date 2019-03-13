#include "property.h"

namespace old::context::data {

Property::Property(memory::InterLevel * il, Prefix prefix, const QString & name)
    : Data(il)
    , prefix(prefix)
    , name(name) {
	m_role = Role::Property;
};



bool Property::checkPrev(const Context * context) const {
	return context != nullptr &&
	       (context->isResultative() || context->isComplex());
}

bool Property::canBeAtEnd() const {
	return true;
}

bool Property::isExecutable() const {
	return m_prev->role() == Role::Object || m_prev->isComplex();
}

memory::StepType::Value Property::execute() {
	newContext = m_prev->runProperty(prefix, name);

	return memory::StepType::MiniStep;
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

}  // namespace old::context::data
