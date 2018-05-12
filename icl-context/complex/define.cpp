#include "define.h"

namespace vm::context::complex {

Define::Define() {}

bool Define::checkPrev(const Context* context) const {
	return context == nullptr;
}

bool Define::canBeAtEnd() const {
	return false;
}

Context* Define::runMethod(const QString& name, memory::ParamList& params) {}

}  // namespace vm::context::complex
