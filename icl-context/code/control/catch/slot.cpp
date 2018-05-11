#include "exists.h"
#include "slot.h"

namespace vm::context::code::control::catch0 {

Slot::Slot () {
	m_role = Role::Slot;
}

void Slot::giveSignal (int code) {
	gettedSignal = code;
};



bool Slot::checkPrev (const Context *context) const {
	return
		context != nullptr &&
		(
		context->role () == Role::Exists ||
		(
			context->role () == Role::Code &&
			context->prev () != nullptr    &&
			context->prev ()->role () == Role::Slot
		)
		);
}

bool Slot::isExecuable () const {
	if (signal == 0) {
		return true;
	}

	return gettedSignal == signal;
}

bool Slot::execute () {

}

Context * Slot::getBeginContext () {
	return getFirst ();
}

Context * Slot::getEndContext () {
	return getLast ();
}

} // namespace
