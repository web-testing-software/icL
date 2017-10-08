#include "ifstackstate.h"
#include "stackstate.h"
#include "virtualmachine.h"


vm::system::StackState::StackState (StackState *prev, int stackLevel) {
	prev_ss				= prev;
	this->stackLevel	= stackLevel;

	if (stackLevel > maxStackLevel) {
		maxStackLevel = stackLevel;
	}
}

vm::system::StackState::~StackState () {

}

void vm::system::StackState::setWebElement (const QString &name, WebElement &webElement) {
	webElementMap [name] = webElement;
}

vm::system::StackState * vm::system::StackState::getPrev () {
	return prev_ss;
}

bool vm::system::StackState::isLast () {
	return prev_ss == nullptr;
}

QVariant vm::system::StackState::getStackValue () {
	return getValue ("stack");
}

int vm::system::StackState::getStackLevel () {
	return stackLevel;
}

bool vm::system::StackState::tryToDestroy () {
	// A loop stack cannot by destryed immediately, it is reused
	// But a commmom stack not
	return true;
}

void vm::system::StackState::releaseCondition () {
	// A commom stack cannot get conditions
	virtualMachine->setError (vm::Error::WRONG_STACK_STATE);
}

int vm::system::StackState::getMaxStackLevel () {
	return maxStackLevel;
}

vm::system::DataState::Type vm::system::StackState::getType (const QString &name) {
	if (webElementMap.contains (name)) {
		return Type::WEB_ELEMENT;
	}
	else {
		return DataState::getType (name);
	}
}

bool vm::system::StackState::checkType (const QString &name, vm::system::DataState::Type &type) {
	if (type == Type::WEB_ELEMENT) {
		return webElementMap.contains (name);
	}
	else {
		return DataState::checkType (name, type);
	}
}

bool vm::system::StackState::contains (const QString &name) {
	if (webElementMap.contains (name)) {
		return true;
	}
	else {
		return DataState::contains (name);
	}
}

QVariant vm::system::StackState::getValue (const QString &name) {
	QVariant res;

	if (webElementMap.contains (name)) {
		res.setValue (webElementMap [name]);
	}
	else {
		res = DataState::getValue (name);
	}

	return res;
}

int vm::system::StackState::maxStackLevel = 0;

vm::system::StackStateIterator::StackStateIterator () {

}

vm::system::StackState * vm::system::StackStateIterator::stack () {
	return m_stack;
}

void vm::system::StackStateIterator::openNewStack (StackState::StackType stackType) {
	int new_stack_level = m_stack->getStackLevel () + 1;

	switch (stackType) {
	case StackState::StackType::COMMOM_STACK :
		m_stack = new StackState (m_stack, new_stack_level);
		break;

	case StackState::StackType::IF_STACK :
		m_stack = new IfStackState (m_stack, new_stack_level);
		break;
	}

}

void vm::system::StackStateIterator::closeStack () {
	StackState *prev = m_stack->getPrev ();

	delete m_stack;
	m_stack = prev;
}

bool vm::system::StackStateIterator::contains (const QString &name) {
	bool		ret = false;
	StackState	*it = m_stack;

	while (!ret && it != nullptr) {
		ret = it->contains (name);
		it	= it->getPrev ();
	}

	return ret;
}

bool vm::system::StackStateIterator::checkType (const QString &name, vm::system::DataState::Type &type) {
	bool		ret = false;
	StackState	*it = m_stack;

	while (!ret && it != nullptr) {
		ret = it->checkType (name, type);
		it	= it->getPrev ();
	}

	return ret;
}

void vm::system::StackStateIterator::clear () {
	StackState *tmp;

	while (m_stack != nullptr) {
		tmp = m_stack->getPrev ();
		delete m_stack;
		m_stack = tmp;
	}
}
