#include "forany.h"

#include <icl-context/base/object/object.h>

namespace icL::context::code {

ForAny::ForAny(memory::InterLevel * il, const memory::CodeFragment & source)
	: Code(il, source) {
	m_role = Role::ForAny;
};



bool ForAny::checkPrev(const Context * context) const {
	return context == nullptr || context->role() == Role::Assign ||
		   context->isResultative();
}

bool ForAny::isExecutable() const {
	return true;
}

memory::StepType::Value ForAny::execute() {
	memory::FunctionCall fcall;

	if (executed) {
		return memory::StepType::MINI_STEP;
	}

	fcall.source = m_source;

	il->vms->interrupt(fcall, [this](memory::Return & ret) {
		if (ret.exception.code != 0) {
			il->vm->exception(ret.exception);
		}
		else {
			newContext = fromValue(ret.consoleValue);
		}
	});

	executed = true;
	return memory::StepType::COMMAND_IN;
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
