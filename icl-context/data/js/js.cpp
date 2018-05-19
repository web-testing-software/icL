#include "js.h"

namespace icL::context::data::js {

Js::Js(memory::InterLevel * il)
	: Context(il) {}

bool Js::canBeAtEnd() const {
	return false;
}

bool Js::isExecuable() const {
	return true;
}

}  // namespace icL::context::data::js
