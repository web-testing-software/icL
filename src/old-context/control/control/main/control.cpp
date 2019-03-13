#include "control.h"

namespace old::context::code::control {


Control::Control(memory::InterLevel * il, const memory::CodeFragment & source)
    : Code(il, source) {}

bool Control::canBeAtEnd() const {
	return false;
}

bool Control::isRightToLeft() const {
	return false;
}

}  // namespace old::context::code::control
