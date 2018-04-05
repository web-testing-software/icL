#include "stackstate.h"
#include "datacontainer.h"

namespace vm::memory {

StackState::StackState (StackState *prev, int stackLevel) {
	prev_ss				= prev;
	this->stackLevel	= stackLevel;

	if (stackLevel > maxStackLevel) {
		maxStackLevel = stackLevel;
	}
}

StackState::~StackState () {

}

void StackState::setWebElement (const QString &name, structures::WebElement &webElement) {
	QVariant tmp = QVariant::fromValue (webElement);

	setValue (name, tmp);
}

StackState * StackState::getPrev () {
	return prev_ss;
}

bool StackState::isLast () {
	return prev_ss == nullptr;
}

QVariant StackState::getStackValue () {
	return getValue ("stack");
}

int StackState::getStackLevel () {
	return stackLevel;
}

int StackState::getMaxStackLevel () {
	return maxStackLevel;
}

int StackState::maxStackLevel = 0;

StackStateIterator::StackStateIterator () {

}

StackStateIterator::~StackStateIterator () {
	clear ();
}

StackState * StackStateIterator::stack () {
	return m_stack;
}

void StackStateIterator::openNewStack () {

	int new_stack_level = m_stack->getStackLevel () + 1;

	m_stack = new StackState (m_stack, new_stack_level);
}

void StackStateIterator::closeStack () {
	StackState *prev = m_stack->getPrev ();

	delete m_stack;
	m_stack = prev;
}

StackState * StackStateIterator::getContainer (const QString &name) {
	StackState	*ret	= nullptr;
	StackState	*it		= m_stack;

	while (ret == nullptr && it != nullptr) {
		if (it->contains (name) ) {
			ret = it;
		}
		else {
			it = it->getPrev ();
		}
	}

	return ret;
}

// bool StackStateIterator::contains (const QString &name) {
//	bool		ret = false;
//	StackState	*it = m_stack;

//	while (!ret && it != nullptr) {
//		ret = it->contains (name);
//		it	= it->getPrev ();
//	}

//	return ret;
// }

// bool StackStateIterator::checkType (const QString &name, DataState::Type &type) {
//	bool		ret = false;
//	StackState	*it = m_stack;

//	while (!ret && it != nullptr) {
//		ret = it->checkType (name, type);
//		it	= it->getPrev ();
//	}

//	return ret;
// }

// QVariant StackStateIterator::getValue (const QString &name) {
//	QVariant	ret;
//	StackState	*it = m_stack;

//	while (ret.isNull () && it != nullptr) {
//		if (it->contains (name) ) {
//			ret = it->getValue (name);
//		}
//		it = it->getPrev ();
//	}

//	return ret;
// }

void StackStateIterator::clear () {
	StackState *tmp;

	while (m_stack != nullptr) {
		tmp = m_stack->getPrev ();
		delete m_stack;
		m_stack = tmp;
	}
}

}
