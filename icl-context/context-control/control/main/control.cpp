#include "control.h"

namespace icL::context::code::control {


Control::Control(const memory::CodeFragment & source)
	: Code(source) {}

bool Control::canBeAtEnd() const {
	return false;
}

bool Control::isRightToLeft() const {
	return false;
}

}  // namespace icL::context::code::control
