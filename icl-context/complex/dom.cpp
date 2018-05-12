#include "dom.h"

namespace vm::context::complex {

Dom::Dom() {}

bool Dom::checkPrev(const Context* context) const {
	return context == nullptr || context->role() == Role::Assign ||
		   (context->role() != Role::Exists && context->isResultative());
}

bool Dom::canBeAtEnd() const {
	return false;
}

Context* Dom::runMethod(const QString& name, memory::ParamList& params) {}

}  // namespace vm::context::complex
