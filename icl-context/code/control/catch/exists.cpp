#include "exists.h"
#include "slot.h"

#include <icl-memory/structures/webelement.h>

namespace vm::context::code::control::catch0 {


Exists::Exists (const memory::CodeFragment &source, bool isEmiter)
	: Catch (source)
	, isEmiter (isEmiter) {
	m_role = Role::Exists;
}

bool Exists::getIsEmiter () const {
	return isEmiter;
};

bool Exists::checkPrev (const Context *context) const {
	return context == nullptr ||
		   context->role () == Role::Alternative ||
		   context->role () == Role::Assign;
}

// Context interface

bool Exists::isExecuable () const {
	return m_prev->role () != Role::Alternative;
}

bool Exists::execute () {
	if (executed) {
		return true;
	}
	else {
		memory::FunctionCall fcall;

		fcall.source = m_source;

		emit interrupt (fcall, [this] (memory::Return &ret) {
						bool isOk = false;

						if (ret.exception.code != 0) {
							Context *it = this->m_next;

							while (it != nullptr) {
								if (it->role () == Role::Slot) {
									auto *slot = dynamic_cast <Slot *> ( it );

									isOk |= slot->giveSignal (ret.exception.code);
								}

								it = it->next ();
							}
						}
						else {
							isOk = true;
						}

						if (isOk) {
							if (!this->isEmiter) {
								if (ret.consoleValue.type () == QVariant::UserType) {
									auto el = ret.consoleValue.value <memory::WebElement>();

									if (el.count == 0) {
										ret.consoleValue = QVariant{};
									}
								}
								else if (ret.consoleValue.toBool () == false) {
									ret.consoleValue = QVariant{};
								}

								this->newContext = fromValue (ret.consoleValue);
							}
						}
						else if (this->isEmiter || ret.exception.code <= -100) {
							emit this->exception (ret.exception);
						}
				});

		executed = true;
		return false;
	}
}

Context * Exists::getBeginContext () {
	return this;
}

Context * Exists::getEndContext () {
	return this;
}

} // namespace
