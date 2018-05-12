#include "list.h"

namespace vm::context::object {



List::List(memory::DataState* container, const QString& varName)
	: Object(container, varName) {}

List::List(const QVariant& rvalue, bool readonly)
	: Object(rvalue, readonly) {}

List::List(const Object* const object)
	: Object(object) {}

}  // namespace vm::context::object
