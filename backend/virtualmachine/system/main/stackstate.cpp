#include "stackstate.h"


vm::system::StackState::StackState (StackState *prev, int stackLevel) {
	prev_ss				= prev;
	this->stackLevel	= stackLevel;
}

vm::system::StackState::~StackState () {

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

vm::system::CommandsToSearch vm::system::StackState::getSearchedCommands () {
	return searchedCommands;
}

void vm::system::StackState::search (const vm::system::CommandsToSearch &commands) {
	searchedCommands = commands;
}

int vm::system::StackState::getStackLevel () {
	return stackLevel;
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

void vm::system::StackStateIterator::openNewStack () {
	int new_stack_level = m_stack->getStackLevel () + 1;

	m_stack = new StackState (m_stack, new_stack_level);
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
