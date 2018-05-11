#include "control.h"

namespace vm::context::code::control {


Control::Control (const memory::CodeFragment &source)
	: Code (source) {
}

bool Control::canBeAtEnd () const {
	return false;
}

bool Control::isRightToLeft () const {
	return false;
}

} // namespace
