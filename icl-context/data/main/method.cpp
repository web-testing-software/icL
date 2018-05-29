#include "method.h"

#include <icl-context/base/object/object.h>


namespace icL::context::data {

Method::Method(memory::InterLevel * il, const QString & name)
	: Data(il)
	, name(name) {
	m_role = Role::Method;
};



bool Method::checkPrev(const Context * context) const {
	return context != nullptr && context->isResultative();
}

bool Method::canBeAtEnd() const {
	return true;
}

memory::StepType Method::execute() {
	memory::ArgList args;
	int             count = 0;
	Context *       it    = m_next;

	while (it != nullptr && it->role() == Role::Object) {
		count++;
		it = it->next();
	}

	endContext = it == nullptr ? getLast() : it->prev();

	if (count > 0) {
		args.reserve(count);
		it = m_next;

		while (it != nullptr && it->role() == Role::Object) {
			memory::Argument arg;

			arg.object = dynamic_cast<object::Object *>(it);
			args.append(arg);

			it = it->next();
		}
	}

	newContext = m_prev->runMethod(name, args);

	return memory::StepType::MiniStep;
}

Context * Method::getBeginContext() {
	return m_prev;
}

Context * Method::getEndContext() {
	return endContext;
}

bool Method::isResultative() const {
	return true;
}

}  // namespace icL::context::data
