#include "stackstate.h"
#include "datacontainer.h"

vm::memory::StackState::StackState (StackState *prev, int stackLevel) {
	prev_ss				= prev;
	this->stackLevel	= stackLevel;

	if (stackLevel > maxStackLevel) {
		maxStackLevel = stackLevel;
	}
}

vm::memory::StackState::~StackState () {

}

void vm::memory::StackState::setWebElement (const QString &name, WebElement &webElement) {
	QVariant tmp = QVariant::fromValue (webElement);

	setValue (name, tmp);
}

vm::memory::StackState * vm::memory::StackState::getPrev () {
	return prev_ss;
}

bool vm::memory::StackState::isLast () {
	return prev_ss == nullptr;
}

QVariant vm::memory::StackState::getStackValue () {
	return getValue ("stack");
}

int vm::memory::StackState::getStackLevel () {
	return stackLevel;
}

bool vm::memory::StackState::tryToDestroy () {
	// A loop stack cannot by destryed immediately, it is reused
	// But a commmom stack not
	return true;
}

void vm::memory::StackState::releaseCondition () {
	// A commom stack cannot get conditions
//	virtualMachine->setError (vm::Error::WRONG_STACK_STATE);
}

int vm::memory::StackState::getMaxStackLevel () {
	return maxStackLevel;
}

int vm::memory::StackState::maxStackLevel = 0;

vm::memory::StackStateIterator::StackStateIterator () {

}

vm::memory::StackStateIterator::~StackStateIterator () {
	clear ();
}

vm::memory::StackState * vm::memory::StackStateIterator::stack () {
	return m_stack;
}

void vm::memory::StackStateIterator::openNewStack (StackState::StackType stackType) {

	//	int new_stack_level = m_stack->getStackLevel () + 1;

	//	switch (stackType) {
	//	case StackState::StackType::COMMOM_STACK :
	//		m_stack = new StackState (m_stack, new_stack_level);
	//		break;

	//	case StackState::StackType::IF_STACK :
	//		m_stack = new IfStackState (m_stack, new_stack_level);
	//		break;
	//	}
}

void vm::memory::StackStateIterator::closeStack () {
	StackState *prev = m_stack->getPrev ();

	delete m_stack;
	m_stack = prev;
}

bool vm::memory::StackStateIterator::contains (const QString &name) {
	bool		ret = false;
	StackState	*it = m_stack;

	while (!ret && it != nullptr) {
		ret = it->contains (name);
		it	= it->getPrev ();
	}

	return ret;
}

bool vm::memory::StackStateIterator::checkType (const QString &name, vm::memory::DataState::Type &type) {
	bool		ret = false;
	StackState	*it = m_stack;

	while (!ret && it != nullptr) {
		ret = it->checkType (name, type);
		it	= it->getPrev ();
	}

	return ret;
}

QVariant vm::memory::StackStateIterator::getValue (const QString &name) {
	QVariant	ret;
	StackState	*it = m_stack;

	while (ret.isNull () && it != nullptr) {
		if (it->contains (name)) {
			ret = it->getValue (name);
		}
		it = it->getPrev ();
	}

	return ret;
}

void vm::memory::StackStateIterator::clear () {
	StackState *tmp;

	while (m_stack != nullptr) {
		tmp = m_stack->getPrev ();
		delete m_stack;
		m_stack = tmp;
	}
}
