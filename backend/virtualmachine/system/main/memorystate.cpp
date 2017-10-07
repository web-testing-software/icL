#include "memorystate.h"
#include "virtualmachine.h"


vm::system::MemoryState::MemoryState () {

}

vm::system::MemoryState::~MemoryState () {

}

bool vm::system::MemoryState::hasPrev () const {
	return prev_ms != nullptr;
}

bool vm::system::MemoryState::hasNext () const {
	return next_ms != nullptr;
}

vm::system::MemoryState * vm::system::MemoryState::getPrev () const {
	return prev_ms;
}

vm::system::MemoryState * vm::system::MemoryState::getNext () const {
	return next_ms;
}

void vm::system::MemoryState::setPrev (vm::system::MemoryState *state) {
	prev_ms = state;
}

void vm::system::MemoryState::setNext (vm::system::MemoryState *state) {
	next_ms = state;
}

vm::system::MemoryStateIterator::MemoryStateIterator () {

}

vm::system::MemoryState * vm::system::MemoryStateIterator::state () const {
	return m_state;
}

void vm::system::MemoryStateIterator::iterateToFirst () {
	while (m_state->getPrev () != nullptr) {
		m_state = m_state->getPrev ();
	}
}

void vm::system::MemoryStateIterator::iterateToLast () {
	while (m_state->getNext () != nullptr) {
		m_state = m_state->getNext ();
	}
}

void vm::system::MemoryStateIterator::appendNewAfter () {
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

void vm::system::MemoryStateIterator::appendNewAtEnd () {
	iterateToLast ();
	appendNewAfter ();
}

void vm::system::MemoryStateIterator::removeState () {
	if (m_state->getNext () == nullptr && m_state->getPrev () == nullptr) {
		delete m_state;
		m_state = nullptr;
	}
	else {
		MemoryState* prev = m_state->getPrev ();
		MemoryState* next = m_state->getNext ();

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
