#include "forany.h"

#include <icl-context/base/object/value.h>

#include <QDebug>

namespace old::context::code {

ForAny::ForAny(memory::InterLevel * il, const memory::CodeFragment & source)
    : Code(il, source) {
	m_role = Role::ForAny;
};



bool ForAny::checkPrev(const Context * context) const {
	return context == nullptr || context->role() == Role::Assign ||
	       context->isResultative();
}

bool ForAny::isRightToLeft() const {
	return true;
}

bool ForAny::isExecutable() const {
	return true;
}

memory::StepType::Value ForAny::execute() {
	memory::FunctionCall fcall;

	if (executed) {
		return memory::StepType::MiniStep;
	}

	fcall.source = m_source;

	il->vms->interrupt(fcall, [this](memory::Return & ret) {
		if (ret.exception.code != 0) {
			il->vm->exception(ret.exception);
			qCritical() << "Any exception";
		}
		else {
			qCritical() << "Any OK!";
			newContext = fromValue(ret.consoleValue);
		}

		this->executed = true;
	});

	return memory::StepType::CommandIn;
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

}  // namespace old::context::code
