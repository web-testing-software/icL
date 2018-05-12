#include "forany.h"

namespace vm::context::code {

ForAny::ForAny (const memory::CodeFragment &source)
	: Code (source) {
	m_role = Role::ForAny;
};



bool ForAny::checkPrev (const Context *context) const {
	return
		context == nullptr               ||
		context->role () == Role::Assign ||
		context->isResultative ();
}

bool ForAny::isExecuable () const {
	return true;
}

bool ForAny::execute () {
	memory::FunctionCall fcall;

	fcall.source = m_source;

	emit interrupt (fcall, [this] (memory::Return &ret) {
					if (ret.exception.code != 0) {
						emit this->exception (ret.exception);
					}
					else {
						newContext = fromValue (ret.consoleValue);
					}
			});

	executed = true;
	return false;
}

Context * ForAny::getBeginContext () {
	return this;
}

Context * ForAny::getEndContext () {
	return this;
}

bool ForAny::isResultative () const {
	return true;
}

} // namespace
