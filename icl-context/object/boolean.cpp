#include "boolean.h"

namespace vm::context::object {



Boolean::Boolean(memory::DataState* container, const QString& varName)
	: Object(container, varName) {}

Boolean::Boolean(const QVariant& rvalue, bool readonly)
	: Object(rvalue, readonly) {}

Boolean::Boolean(const Object* const object)
	: Object(object) {}

}  // namespace vm::context::object
