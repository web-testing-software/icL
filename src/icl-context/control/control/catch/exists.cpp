#include "exists.h"

#include "slot.h"

#include <icl-context/base/object/object.h>
#include <icl-memory/structures/element.h>

namespace icL::context::code::control::catch0 {


Exists::Exists(
  memory::InterLevel * il, const memory::CodeFragment & source, bool isEmiter)
	: Catch(il, source)
	, isEmiter(isEmiter) {
	m_role = Role::Exists;
}

bool Exists::getIsEmiter() const {
	return isEmiter;
};

bool Exists::checkPrev(const Context * context) const {
	return context == nullptr || context->role() == Role::Alternative ||
		   context->role() == Role::Assign;
}

// Context interface

bool Exists::isExecutable() const {
	return m_prev == nullptr || m_prev->role() != Role::Alternative;
}

memory::StepType::Value Exists::execute() {
	if (executed) {
		return memory::StepType::MiniStep;
	}
	else {
		memory::FunctionCall fcall;

		fcall.source = m_source;

		il->vms->interrupt(fcall, [this](memory::Return & ret) {
			bool isOk = false;

			if (ret.exception.code != 0) {
				Context * it = this->m_next;

				while (it != nullptr) {
					if (it->role() == Role::Slot) {
						auto * slot = dynamic_cast<Slot *>(it);

						isOk |= slot->giveSignal(ret.exception.code);
					}

					it = it->next();
				}
			}
			else {
				isOk = true;
			}

			if (isOk) {
				if (!this->isEmiter) {
					if (ret.consoleValue.type() == QVariant::UserType) {
						auto el = ret.consoleValue.value<memory::Element>();

						if (el.count == 0) {
							ret.consoleValue = QVariant{};
						}
					}
					else if (ret.consoleValue.toBool() == false) {
						ret.consoleValue = QVariant{};
					}

					this->newContext = fromValue(ret.consoleValue);
				}
			}
			else if (this->isEmiter || ret.exception.code <= -100) {
				il->vm->exception(ret.exception);
			}

			this->executed = true;
		});
	}

	return memory::StepType::CommandIn;
}

Context * Exists::getBeginContext() {
	return this;
}

Context * Exists::getEndContext() {
	return this;
}

bool Exists::isResultative() const {
	return true;
}

}  // namespace icL::context::code::control::catch0
