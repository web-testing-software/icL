#include "exception.h"

namespace icL::memory {



Exception::Exception(int code, const QString& message)
	: code(code)
	, message(message) {}

}  // namespace icL::memory
