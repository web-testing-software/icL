#include "memorystate.h"
#include "virtualmachine.h"


vm::memory::MemoryState::MemoryState () {

}

vm::memory::MemoryState::~MemoryState () {

}

bool vm::memory::MemoryState::hasPrev () const {
	return prev_ms != nullptr;
}

bool vm::memory::MemoryState::hasNext () const {
	return next_ms != nullptr;
}

vm::memory::MemoryState * vm::memory::MemoryState::getPrev () const {
	return prev_ms;
}

vm::memory::MemoryState * vm::memory::MemoryState::getNext () const {
	return next_ms;
}

void vm::memory::MemoryState::setPrev (vm::memory::MemoryState *state) {
	prev_ms = state;
}

void vm::memory::MemoryState::setNext (vm::memory::MemoryState *state) {
	next_ms = state;
}

vm::memory::MemoryStateIterator::MemoryStateIterator () {

}

vm::memory::MemoryStateIterator::~MemoryStateIterator () {
	clear ();
}

vm::memory::MemoryState * vm::memory::MemoryStateIterator::state () const {
	return m_state;
}

void vm::memory::MemoryStateIterator::iterateToFirst () {
	if (m_state != nullptr) {
		while (m_state->getPrev () != nullptr) {
			m_state = m_state->getPrev ();
		}
	}
}

void vm::memory::MemoryStateIterator::iterateToLast () {
	if (m_state != nullptr) {
		while (m_state->getNext () != nullptr) {
			m_state = m_state->getNext ();
		}
	}
}

void vm::memory::MemoryStateIterator::appendNewAfter () {
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

//		if (virtualMachine->memoryStateToStop () == m_state) {
//			virtualMachine->setMemoryStateToStop (new_state);
//		}

		m_state = new_state;
	}
}

void vm::memory::MemoryStateIterator::appendNewAtEnd () {
	iterateToLast ();
	appendNewAfter ();
}

void vm::memory::MemoryStateIterator::removeState () {
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

void vm::memory::MemoryStateIterator::clear () {
	iterateToFirst ();

	MemoryState *tmp;

	while (m_state != nullptr) {
		tmp = m_state->getNext ();
		delete m_state;
		m_state = tmp;
	}
}
