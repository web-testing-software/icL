#include "memorystate.h"
#include "virtualmachine.h"


vm::main::MemoryState::MemoryState () {

}

vm::main::MemoryState::~MemoryState () {

}

bool vm::main::MemoryState::hasPrev () const {
	return prev_ms != nullptr;
}

bool vm::main::MemoryState::hasNext () const {
	return next_ms != nullptr;
}

vm::main::MemoryState * vm::main::MemoryState::getPrev () const {
	return prev_ms;
}

vm::main::MemoryState * vm::main::MemoryState::getNext () const {
	return next_ms;
}

void vm::main::MemoryState::setPrev (vm::main::MemoryState *state) {
	prev_ms = state;
}

void vm::main::MemoryState::setNext (vm::main::MemoryState *state) {
	next_ms = state;
}

vm::main::MemoryStateIterator::MemoryStateIterator () {

}

vm::main::MemoryState * vm::main::MemoryStateIterator::state () const {
	return m_state;
}

void vm::main::MemoryStateIterator::iterateToFirst () {
	if (m_state != nullptr) {
		while (m_state->getPrev () != nullptr) {
			m_state = m_state->getPrev ();
		}
	}
}

void vm::main::MemoryStateIterator::iterateToLast () {
	if (m_state != nullptr) {
		while (m_state->getNext () != nullptr) {
			m_state = m_state->getNext ();
		}
	}
}

void vm::main::MemoryStateIterator::appendNewAfter () {
	if (m_state == nullptr) {
		m_state = new MemoryState ();
	}
	else {
		MemoryState *new_state	= new MemoryState ();
		MemoryState *next_state = m_state->getNext ();

		if (next_state != nullptr) {
			next_state->setPrev (new_state);
		}
		new_state->setNext (next_state);
		new_state->setPrev (m_state);
		m_state->setNext (new_state);

		if (virtualMachine->memoryStateToStop () == m_state) {
			virtualMachine->setMemoryStateToStop (new_state);
		}

		m_state = new_state;
	}
}

void vm::main::MemoryStateIterator::appendNewAtEnd () {
	iterateToLast ();
	appendNewAfter ();
}

void vm::main::MemoryStateIterator::removeState () {
	if (m_state->getNext () == nullptr && m_state->getPrev () == nullptr) {
		delete m_state;
		m_state = nullptr;
	}
	else {
		MemoryState *prev	= m_state->getPrev ();
		MemoryState *next	= m_state->getNext ();

		if (prev != nullptr) {
			prev->setNext (next);
		}
		if (next != nullptr) {
			next->setPrev (prev);
		}

		delete m_state;
		m_state = next;
	}
}

void vm::main::MemoryStateIterator::clear () {
	iterateToFirst ();

	MemoryState *tmp;

	while (m_state != nullptr) {
		tmp = m_state->getNext ();
		delete m_state;
		m_state = tmp;
	}
}
