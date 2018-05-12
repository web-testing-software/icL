#include "string.h"

namespace vm::context::object {



String::String(memory::DataState* container, const QString& varName)
	: Object(container, varName) {}

String::String(const QVariant& rvalue, bool readonly)
	: Object(rvalue, readonly) {}

String::String(const Object* const object)
	: Object(object) {}

}  // namespace vm::context::object
