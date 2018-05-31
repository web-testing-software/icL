#include "virtualmachine.h"

#include "vmstack.h"

#include <icl-context/base/object/object.h>


namespace icL {

VirtualMachine::VirtualMachine(
  VMStack * vms, VirtualMachine * parent, QString * source)
	: interpreter(&il)
	, parent(parent)
	, m_source(source)
	, waiting_mode(parent == nullptr) {

	// Initialize interlevel object
	if (parent != nullptr) {
		il = parent->il;
	}
	else {
		il.mem    = vms->memory();
		il.server = vms->server();
		il.inter  = &interpreter;
		il.vm     = this;
		il.vms    = vms;
	}

	il.mem->stackIt().openNewStack();
}

VirtualMachine * VirtualMachine::getParent() const {
	return parent;
}

memory::StepType::Value VirtualMachine::step() {
	if (!running) {
		finish();
		return memory::StepType::NONE;
	}

	if (commandParsing) {
		context::Context * next = interpreter.parseNext();

		return prepareNext(next);
	}
	else {
		context::Context * executable = findExecutable();

		return prepareExecutable(executable);
	}
}

void VirtualMachine::setOnStop(std::function<void(memory::Return &)> feedback) {
	onStop = feedback;
}

void VirtualMachine::reset() {
	r_exception = {0, ""};
	running     = true;
}

void VirtualMachine::fullReset() {
	auto it = last_context;

	while (it->prev() != nullptr) {
		it = it->prev();
	}

	it = it->next();

	while (it != nullptr) {
		delete it->prev();
	}

	delete last_context;

	last_context = nullptr;
	r_result     = {};

	reset();
}

void VirtualMachine::setFragLimits(int left, int right) {
	interpreter.ride(left, right);
}

void VirtualMachine::exception(const memory::Exception & exc) {
	// TODO: Write it
}

QString * VirtualMachine::source() {
	return m_source;
}

void VirtualMachine::finish() {
	r_result.returnValue = il.mem->stackIt().stack()->getValue("stack");
	il.mem->stackIt().closeStack();

	if (onStop != nullptr) {
		onStop(r_result);
	}
}

context::Context * VirtualMachine::findExecutable() {
	context::Context * ret = nullptr;
	context::Context * it  = last_context;

	while (it != nullptr && it->prev() != nullptr) {
		if (it->isRightToLeft() && it->isExecutable()) {
			ret = it;
			break;
		}
		it = it->prev();
	}

	if (ret == nullptr) {
		while (it == nullptr) {
			if (it->isExecutable()) {
				ret = it;
				break;
			}
		}
	}

	return ret;
}

memory::StepType::Value VirtualMachine::prepareNext(context::Context * next) {
	if (next == nullptr) {
		if (last_context == nullptr) {
			finish();
			return memory::StepType::NONE;
		}

		if (!last_context->canBeAtEnd()) {
			exception({-101, "Command not finished, but ; expected"});
		}

		int pos = interpreter.getFlayer().getPosition();
		il.vms->highlight(pos, pos + 1);

		commandParsing = false;
		return memory::StepType::MINI_STEP;
	}

	if (next->checkPrev(last_context)) {
		if (last_context != nullptr) {
			last_context->link(next);
		}

		last_context = next;

		il.vms->highlight(
		  next->getBeginCursorPosition(), next->getEndCursorPosition());
	}
	else {
		exception({-100, "Wrong sematic blocks order"});
	}

	return memory::StepType::MINI_STEP;
}

memory::StepType::Value VirtualMachine::prepareExecutable(
  context::Context * executable) {
	if (executable == nullptr) {
		if (
		  last_context != nullptr && last_context->next() == nullptr &&
		  last_context->prev() == nullptr) {
			if (last_context->role() == context::Role::Object) {
				r_result.consoleValue =
				  dynamic_cast<context::object::Object *>(last_context)
					->getValue();

				delete last_context;
				last_context = nullptr;
			}
			else {
				r_result.consoleValue = QVariant{};
			}
		}

		int pos = il.inter->getFlayer().getPosition();

		il.vms->highlight(pos, pos + 1);

		interpreter.getFlayer().stepForward();
		commandParsing = true;
		return memory::StepType::COMMAND_END;
	}

	memory::StepType::Value value = executable->execute();

	il.vms->highlight(
	  executable->getBeginContext()->getBeginCursorPosition(),
	  executable->getEndContext()->getEndCursorPosition());

	if (value == memory::StepType::MINI_STEP) {
		destroy(executable);
	}
	else if (value == memory::StepType::NONE) {
		// Don't destroy vm, it can be reseted later
		value = memory::StepType::MINI_STEP;
	}

	return value;

	return memory::StepType::MINI_STEP;
}

void VirtualMachine::destroy(context::Context * executable) {
	auto * begin      = executable->getBeginContext();
	auto * new_       = executable->getNewContext();
	auto * end        = executable->getEndContext();
	auto * begin_prev = begin->prev();
	auto * end_next   = end->next();

	auto * it = begin->next();

	while (it != end_next) {
		delete it->prev();
		it = it->next();
	}

	if (end_next == nullptr || begin == end) {
		delete end;
	}

	if (last_context == end) {
		last_context = new_ != nullptr ? new_ : begin_prev;
	}

	context::Context::link(begin_prev, new_, end_next);
}

}  // namespace icL