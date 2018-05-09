#include "exists.h"
#include "slot.h"

namespace vm::context::code::control::catch0 {

Slot::Slot () {
	m_role = Role::Slot;
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

	Context *it = m_prev;

	while (it && it->role () != Role::Exists) {
		it = it->prev ();
	}

	if (it == nullptr) {
		emit exception (-102, "Signal generator is missing");
		return false;
	}
	else {
		return dynamic_cast <Exists *> ( it )->signal () == signal;
	}
}

bool Slot::execute () const {

}

const Context *Slot::getBeginContext() const {

}

const Context *Slot::getEndContext() const {

}

} // namespace
