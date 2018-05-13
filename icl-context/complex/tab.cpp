#include "tab.h"

namespace vm::context::complex {

Tab::Tab() {}

bool Tab::checkPrev(const Context* context) const {
	return context == nullptr;
}

bool Tab::canBeAtEnd() const {
	return false;
}

Context* Tab::runMethod(const QString& name, memory::ArgList &args) {}

}  // namespace vm::context::complex
