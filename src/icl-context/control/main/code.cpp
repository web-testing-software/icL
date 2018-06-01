#include "code.h"

#include <icl-context/base/object/object.h>

namespace icL::context::code {

Code::Code(memory::InterLevel * il, const memory::CodeFragment & source)
	: Context(il)
	, m_source(source) {
	m_role = Role::Code;
}

const memory::CodeFragment & Code::source() const {
	return m_source;
}

bool Code::checkPrev(const Context * context) const {
	return context != nullptr &&
		   (context->role() == Role::If || context->role() == Role::Else ||
			context->role() == Role::Slot ||
			context->role() == Role::Argument ||
			(context->role() == Role::Assign && context->prev() != nullptr &&
			 context->prev()->role() == Role::Function) ||
			context->isResultative());
}

bool Code::isRightToLeft() const {
	return false;
}

bool Code::canBeAtEnd() const {
	return true;
}

bool Code::isExecutable() const {
	return m_prev->role() == Role::Object;
}

memory::StepType::Value Code::execute() {
	if (executed) {
		return memory::StepType::MINI_STEP;
	}
	else {
		memory::FunctionCall fcall;
		memory::Argument     arg;

		if (m_prev->role() == context::Role::Object) {
			arg.name   = "stack";
			arg.object = dynamic_cast<context::object::Object *>(m_prev);

			fcall.source = m_source;
			fcall.args.append(arg);
		}

		il->vms->interrupt(fcall, [this](memory::Return & ret) {
			if (ret.exception.code != 0) {
				this->il->vm->exception(ret.exception);
			}

			this->executed = true;
		});

		return memory::StepType::COMMAND_IN;
	}
}

Context * Code::getBeginContext() {
	return this;
}

Context * Code::getEndContext() {
	return this;
}

}  // namespace icL::context::code
