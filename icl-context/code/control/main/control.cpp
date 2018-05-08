#include "control.h"

namespace vm::context::code::control {

Control::Control () = default;



bool Control::canBeAtEnd () const {
	return false;
}

bool Control::isRightToLeft () const {
	return false;
}

} // namespace
