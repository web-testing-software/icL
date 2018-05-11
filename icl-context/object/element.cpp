#include "element.h"

namespace vm::context::object {



Element::Element (memory::DataState *container, const QString &varName)	\
		: Object (container, varName) {

	}

Element::Element (const QVariant &rvalue, bool readonly)
	: Object (rvalue, readonly) {

}

Element::Element (const Object *const object)
	: Object (object) {

}

} // namespace
