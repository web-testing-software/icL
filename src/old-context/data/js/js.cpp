#include "js.h"

namespace old::context::data::js {

Js::Js(memory::InterLevel * il)
    : Context(il) {}

bool Js::canBeAtEnd() const {
	return false;
}

bool Js::isExecutable() const {
	return true;
}

}  // namespace old::context::data::js
