#include "exception.h"

namespace vm::memory {



Exception::Exception(int code, const QString& message)
	: code(code)
	, message(message) {}

}  // namespace vm::memory
