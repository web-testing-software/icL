#include "forany.h"

#include <object/object.h>

namespace icL::context::code {

ForAny::ForAny(memory::InterLevel * il, const memory::CodeFragment & source)
	: Code(il, source) {
	m_role = Role::ForAny;
};



bool ForAny::checkPrev(const Context * context) const {
	return context == nullptr || context->role() == Role::Assign ||
		   context->isResultative();
}

bool ForAny::isExecuable() const {
	return true;
}

bool ForAny::execute() {
	memory::FunctionCall fcall;

	fcall.source = m_source;

	memory::Return ret = il->vms->interrupt(fcall);
		if (ret.exception.code != 0) {
			il->vm->exception(ret.exception);
		}
		else {
			newContext = fromValue(ret.consoleValue);
		}

	executed = true;
	return false;
}

Context * ForAny::getBeginContext() {
	return this;
}

Context * ForAny::getEndContext() {
	return this;
}

bool ForAny::isResultative() const {
	return true;
}

}  // namespace icL::context::code
