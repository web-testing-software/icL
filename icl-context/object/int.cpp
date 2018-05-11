#include "int.h"

namespace vm::context::object {

Int::Int () = default;



Int::Int (memory::DataState *container, const QString &varName)
	: Object (container, varName) {

}

Int::Int (const QVariant &rvalue, bool readonly)
	: Object (rvalue, readonly) {

}

Int::Int (const Object *const object)
	: Object (object) {

}

} // namespace
