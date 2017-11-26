#include "../logic/main/logicblock.h"
#include "ifstackstate.h"
#include "stackstate.h"
#include "virtualmachine.h"

vm::main::StackState::StackState (StackState *prev, int stackLevel) {
	prev_ss				= prev;
	this->stackLevel	= stackLevel;

	if (stackLevel > maxStackLevel) {
		maxStackLevel = stackLevel;
	}
}

vm::main::StackState::~StackState () {

}

void vm::main::StackState::setWebElement (const QString &name, WebElement &webElement) {
	webElementMap [name] = webElement;
}

vm::main::StackState * vm::main::StackState::getPrev () {
	return prev_ss;
}

bool vm::main::StackState::isLast () {
	return prev_ss == nullptr;
}

QVariant vm::main::StackState::getStackValue () {
	return getValue ("stack");
}

int vm::main::StackState::getStackLevel () {
	return stackLevel;
}

bool vm::main::StackState::tryToDestroy () {
	// A loop stack cannot by destryed immediately, it is reused
	// But a commmom stack not
	return true;
}

void vm::main::StackState::releaseCondition () {
	// A commom stack cannot get conditions
	virtualMachine->setError (vm::Error::WRONG_STACK_STATE);
}

int vm::main::StackState::getMaxStackLevel () {
	return maxStackLevel;
}

vm::main::DataState::Type vm::main::StackState::getType (const QString &name) {
	if (webElementMap.contains (name)) {
		return Type::WEB_ELEMENT;
	}
	else {
		return DataState::getType (name);
	}
}

bool vm::main::StackState::checkType (const QString &name, vm::main::DataState::Type &type) {
	if (type == Type::WEB_ELEMENT) {
		return webElementMap.contains (name);
	}
	else {
		return DataState::checkType (name, type);
	}
}

bool vm::main::StackState::contains (const QString &name) {
	if (webElementMap.contains (name)) {
		return true;
	}
	else {
		return DataState::contains (name);
	}
}

QVariant vm::main::StackState::getValue (const QString &name) {
	QVariant res;

	if (webElementMap.contains (name)) {
		res.setValue (webElementMap [name]);
	}
	else {
		res = DataState::getValue (name);
	}

	return res;
}

int vm::main::StackState::maxStackLevel = 0;

vm::main::StackStateIterator::StackStateIterator () {

}

vm::main::StackState * vm::main::StackStateIterator::stack () {
	return m_stack;
}

void vm::main::StackStateIterator::openNewStack (StackState::StackType stackType) {
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

void vm::main::StackStateIterator::closeStack () {
	StackState *prev = m_stack->getPrev ();

	delete m_stack;
	m_stack = prev;
}

bool vm::main::StackStateIterator::contains (const QString &name) {
	bool		ret = false;
	StackState	*it = m_stack;

	while (!ret && it != nullptr) {
		ret = it->contains (name);
		it	= it->getPrev ();
	}

	return ret;
}

bool vm::main::StackStateIterator::checkType (const QString &name, vm::main::DataState::Type &type) {
	bool		ret = false;
	StackState	*it = m_stack;

	while (!ret && it != nullptr) {
		ret = it->checkType (name, type);
		it	= it->getPrev ();
	}

	return ret;
}

QVariant vm::main::StackStateIterator::getValue (const QString &name) {
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

void vm::main::StackStateIterator::clear () {
	StackState *tmp;

	while (m_stack != nullptr) {
		tmp = m_stack->getPrev ();
		delete m_stack;
		m_stack = tmp;
	}
}
