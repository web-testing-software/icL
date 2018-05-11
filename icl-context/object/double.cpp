#include "double.h"

namespace vm::context::object {



Double::Double (memory::DataState *container, const QString &varName)
	: Object (container, varName) {

}

Double::Double (const QVariant &rvalue, bool readonly)
	: Object (rvalue, readonly) {

}

Double::Double (const Object *const object)
	: Object (object) {

}

} // namespace
