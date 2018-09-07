#include "virtualmachine.h"

#include "vmstack.h"

#include <icl-context/base/object/value.h>


namespace icL {

VirtualMachine::VirtualMachine(
  VMStack * vms, VirtualMachine * parent, QString * source)
	: interpreter(&il)
	, parent(parent)
	, m_source(source)
	, waiting_mode(parent == nullptr) {

	vms->memory()->stackIt().openNewStack();

	// Initialize interlevel object
	if (parent != nullptr) {
		il = parent->il;
	}
	else {
		il.mem    = vms->memory();
		il.server = vms->server();
		il.vms    = vms;

		// waiting_mode = true;
		il.mem->stackIt().stack()->setValue("stack", true);
	}

	il.inter = &interpreter;
	il.vm    = this;
}

VirtualMachine * VirtualMachine::getParent() const {
	return parent;
}

memory::StepType::Value VirtualMachine::step() {
	if (!running) {
		finish();
		return memory::StepType::None;
	}

	memory::StepType::Value value;

	if (commandParsing) {
		context::Context * next = interpreter.parseNext();

		value = prepareNext(next);
	}
	else {
		context::Context * executable = findExecutable();

		value = prepareExecutable(executable);
	}

	auto        it = last_context;
	QStringList l;

	while (it != nullptr) {
		if (it->role() == context::Role::Object) {
			l.prepend(
			  "Object:" +
			  memory::typeToString(
				dynamic_cast<context::value::Value *>(it)->type()));
		}
		else {
			l.prepend(context::roleToString(it->role()));
		}
		it = it->prev();
	}

	// Hightlight with orange color
	qWarning() << l.join(" <> ");

	return value;
}

void VirtualMachine::setOnStop(std::function<void(memory::Return &)> feedback) {
	onStop = feedback;
}

void VirtualMachine::reset() {
	r_result.exception = {0, {}};
	running            = true;
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
	if (left < 0) {
		left = interpreter.getFlayer().getPosition();
	}

	interpreter.ride(left, right);
	code_begin = left;
	code_end   = right;
}

void VirtualMachine::exception(const memory::Exception & exc) {
	r_result.exception = exc;
	running            = false;

	if (parent == nullptr) {
		il.vms->exit(exc);
	}
}

QString * VirtualMachine::source() {
	return m_source;
}

QVariant VirtualMachine::getConsoleValue() {
	return r_result.consoleValue;
}

void VirtualMachine::finish() {
	r_result.returnValue = il.mem->stackIt().stack()->getValue("stack");
	il.mem->stackIt().closeStack();

	if (onStop != nullptr) {
		onStop(r_result);
	}
	else {
		//		il.vms->
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
		while (it != nullptr) {
			if (it->isExecutable()) {
				ret = it;
				break;
			}
			it = it->next();
		}
	}

	return ret;
}

memory::StepType::Value VirtualMachine::prepareNext(context::Context * next) {
	if (next == nullptr) {
		if (last_context == nullptr) {
			finish();
			if (code_begin != 0) {
				il.vms->setSColor(memory::SelectionColor::Destroying);
				il.vms->highlight(code_begin - 1, code_end + 1);
			}
			return memory::StepType::None;
		}

		if (!last_context->canBeAtEnd()) {
			il.vms->setSColor(memory::SelectionColor::Error);
			il.vms->highlight(
			  last_context->getBeginCursorPosition(),
			  last_context->getEndCursorPosition());

			exception({-101, "Command not finished, but ; expected"});
		}
		else {
			int pos = interpreter.getFlayer().getPosition();

			il.vms->highlight(pos, pos + 1);
			il.vms->setSColor(memory::SelectionColor::Parsing);
		}

		commandParsing = false;
		return memory::StepType::MiniStep;
	}

	if (next->checkPrev(last_context)) {
		if (last_context != nullptr) {
			last_context->link(next);
		}

		last_context = next;

		il.vms->highlight(
		  next->getBeginCursorPosition(), next->getEndCursorPosition());
		il.vms->setSColor(memory::SelectionColor::Parsing);
	}
	else {
		exception({-100, "Wrong sematic blocks order"});
	}

	return memory::StepType::MiniStep;
}

memory::StepType::Value VirtualMachine::prepareExecutable(
  context::Context * executable) {
	if (executable == nullptr) {
		if (
		  last_context != nullptr && last_context->next() == nullptr &&
		  last_context->prev() == nullptr) {
			if (last_context->role() == context::Role::Object) {
				r_result.consoleValue =
				  dynamic_cast<context::value::Value *>(last_context)
					->getValue();

				delete last_context;
				last_context = nullptr;
			}
			else {
				r_result.consoleValue = QVariant{};
			}
		}

		int pos = il.inter->getFlayer().getPosition();

		il.vms->setSColor(memory::SelectionColor::Executing);
		il.vms->highlight(pos, pos + 1);

		interpreter.getFlayer().stepForward();
		commandParsing = true;
		return memory::StepType::CommandEnd;
	}

	memory::StepType::Value value = executable->execute();

	if (value == memory::StepType::MiniStep) {
		il.vms->highlight(
		  executable->getBeginContext()->getBeginCursorPosition(),
		  executable->getEndContext()->getEndCursorPosition());
		il.vms->setSColor(memory::SelectionColor::Executing);

		destroy(executable);
	}
	else if (value == memory::StepType::None) {
		il.vms->setSColor(memory::SelectionColor::Error);
		il.vms->highlight(
		  executable->getBeginCursorPosition(),
		  executable->getEndCursorPosition());

		// Don't destroy vm, it can be reseted later
		value = memory::StepType::MiniStep;
	}

	return value;

	//	return memory::StepType::MiniStep;
}

void VirtualMachine::destroy(context::Context * executable) {
	auto * begin      = executable->getBeginContext();
	auto * new_       = executable->getNewContext();
	auto * end        = executable->getEndContext();
	auto * begin_prev = begin->prev();
	auto * end_next   = end->next();

	if (new_ != nullptr) {
		new_->setCursorPositions(
		  begin->getBeginCursorPosition(), end->getEndCursorPosition());
	}

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
