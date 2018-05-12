#include "memorystate.h"

namespace vm::memory {

MemoryState::MemoryState() = default;

MemoryState::~MemoryState() = default;

// bool MemoryState::hasPrev () const {
//	return prev_ms != nullptr;
//}

// bool MemoryState::hasNext () const {
//	return next_ms != nullptr;
//}

// MemoryState * MemoryState::getPrev () const {
//	return prev_ms;
//}

// MemoryState * MemoryState::getNext () const {
//	return next_ms;
//}

// void MemoryState::setPrev (MemoryState *state) {
//	prev_ms = state;
//}

// void MemoryState::setNext (MemoryState *state) {
//	next_ms = state;
//}

MemoryStateIt::MemoryStateIt() {
	m_state = new MemoryState();
}

MemoryStateIt::~MemoryStateIt() {
	delete m_state;
	//	clear ();
}

MemoryState* MemoryStateIt::state() const {
	return m_state;
}

/// Doesn't delete the commented code, it will be uncommented in the version 1.2

// void MemoryStateIterator::iterateToFirst () {
//	if (m_state != nullptr) {
//		while (m_state->getPrev () != nullptr) {
//			m_state = m_state->getPrev ();
//		}
//	}
//}

// void MemoryStateIterator::iterateToLast () {
//	if (m_state != nullptr) {
//		while (m_state->getNext () != nullptr) {
//			m_state = m_state->getNext ();
//		}
//	}
//}

// void MemoryStateIterator::appendNewAfter () {
//	if (m_state == nullptr) {
//		m_state = new MemoryState ();
//	}
//	else {
//		MemoryState *new_state	= new MemoryState ();
//		MemoryState *next_state = m_state->getNext ();

//		if (next_state != nullptr) {
//			next_state->setPrev (new_state);
//		}
//		new_state->setNext (next_state);
//		new_state->setPrev (m_state);
//		m_state->setNext (new_state);

////		if (virtualMachine->memoryStateToStop () == m_state) {
////			virtualMachine->setMemoryStateToStop (new_state);
////		}

//		m_state = new_state;
//	}
//}

// void MemoryStateIterator::appendNewAtEnd () {
//	iterateToLast ();
//	appendNewAfter ();
//}

// void MemoryStateIterator::removeState () {
//	if (m_state->getNext () == nullptr && m_state->getPrev () == nullptr) {
//		delete m_state;
//		m_state = nullptr;
//	}
//	else {
//		MemoryState *prev	= m_state->getPrev ();
//		MemoryState *next	= m_state->getNext ();

//		if (prev != nullptr) {
//			prev->setNext (next);
//		}
//		if (next != nullptr) {
//			next->setPrev (prev);
//		}

//		delete m_state;
//		m_state = next;
//	}
//}

// void MemoryStateIterator::clear () {
//	iterateToFirst ();

//	MemoryState *tmp;

//	while (m_state != nullptr) {
//		tmp = m_state->getNext ();
//		delete m_state;
//		m_state = tmp;
//	}
//}

}  // namespace vm::memory
