#include "method.h"

#include <icl-context/base/object/object.h>


namespace icL::context::data {

Method::Method(memory::InterLevel * il, const QString & name)
	: Data(il)
	, name(name) {
	m_role = Role::Method;
};



bool Method::checkPrev(const Context * context) const {
	return context != nullptr &&
		   (context->isResultative() || context->isComplex());
}

bool Method::canBeAtEnd() const {
	return true;
}

bool Method::isExecutable() const {
	return m_prev->role() == Role::Object || m_prev->isComplex();
}

memory::StepType::Value Method::execute() {
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

	return memory::StepType::MINI_STEP;
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
