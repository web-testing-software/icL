#include "slot.h"

#include "exists.h"

namespace vm::context::code::control::catch0 {

Slot::Slot()
	: Catch(memory::CodeFragment()) {
	m_role = Role::Slot;
}

bool Slot::giveSignal(int code) {
	gettedSignal = code;

	return signal == 0 || code == signal;
};



bool Slot::checkPrev(const Context* context) const {
	return context != nullptr &&
		   ((context->role() == Role::Exists && context->prev() == nullptr &&
			 dynamic_cast<const Exists*>(context)->getIsEmiter()) ||
			(context->role() == Role::Code && context->prev() != nullptr &&
			 context->prev()->role() == Role::Slot));
}

bool Slot::isExecuable() const {
	return signal == 0 || gettedSignal == signal;
}

bool Slot::execute() {
	return m_next->execute();
}

Context* Slot::getBeginContext() {
	return getFirst();
}

Context* Slot::getEndContext() {
	return getLast();
}

}  // namespace vm::context::code::control::catch0
