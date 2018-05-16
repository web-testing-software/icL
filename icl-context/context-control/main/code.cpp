#include "code.h"

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
		   (context->role() == Role::Else || context->role() == Role::Slot ||
			context->role() == Role::Argument ||
			(context->role() == Role::Assign && context->prev() != nullptr &&
			 context->prev()->role() == Role::Function) ||
			context->isResultative());
}

bool Code::canBeAtEnd() const {
	return true;
}

bool Code::isExecuable() const {
	return m_prev->role() == Role::Object;
}

bool Code::execute() {
	if (executed) {
		return true;
	}
	else {
		memory::FunctionCall fcall;

		fcall.source = m_source;

		emit interrupt(fcall, [this](memory::Return & ret) {
			if (ret.exception.code != 0) {
				emit this->exception(ret.exception);
			}
		});

		executed = true;
		return false;
	}
}

Context * Code::getBeginContext() {
	return this;
}

Context * Code::getEndContext() {
	return this;
}

}  // namespace icL::context::code
