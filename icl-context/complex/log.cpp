#include "log.h"

namespace vm::context::complex {

Log::Log() {}

bool Log::checkPrev(const Context* context) const {
	return context == nullptr;
}

bool Log::canBeAtEnd() const {
	return false;
}

Context* Log::runMethod(const QString& name, memory::ArgList &args) {}

}  // namespace vm::context::complex
