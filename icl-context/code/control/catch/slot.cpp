#include "exists.h"
#include "slot.h"

namespace vm::context::code::control::catch0 {

Slot::Slot () = default;



bool Slot::isExecuable () {
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

} // namespace
