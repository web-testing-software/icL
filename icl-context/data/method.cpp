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

bool Method::execute () {
	memory::ParamList params;
	int count = 0;
	Context* it = m_next;

	while (it != nullptr && it->role() == Role::Object) {
		count++;
		it = it->next();
	}

	endContext = it == nullptr ? getLast() : it->prev();

	if (count > 0) {
		params.reserve(count);
		it = m_next;

		while (it != nullptr && it->role() == Role::Object) {
			memory::Parameter param;

			param.object = it;
			params.append(param);

			it = it->next();
		}
	}

	newContext = m_prev->runMethod(name, params);

	return true;
}

Context * Method::getBeginContext () {
	return m_prev;
}

Context * Method::getEndContext () {
	return endContext;
}

} // namespace
