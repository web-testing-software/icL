#include "virtualmachine.h"

vm::system::VirtualMachine *vm::system::VirtualMachine::m_instance = nullptr;

vm::system::VirtualMachine::VirtualMachine () {
	if (m_instance == nullptr) {
		m_instance = this;
	}
}

vm::system::MemoryStateIterator * vm::system::VirtualMachine::memoryStateIt () {
	return &m_memoryStateIt;
}

vm::system::StackStateIterator * vm::system::VirtualMachine::stackStateIt () {
	return &m_stackStateIt;
}

vm::system::VirtualMachine * vm::system::VirtualMachine::instance () {
	return m_instance;
}

void vm::system::VirtualMachine::openFile (const QString &path) {

}

bool vm::system::VirtualMachine::containsVar (const QString &name) {
	return memoryState->contains (name) || m_stackStateIt.contains (name);
}

void vm::system::VirtualMachine::setError (vm::Error error) {
	this->error = error;
}

void vm::system::VirtualMachine::setStepNumber (int step) {
	stepNumber = step;
}

void vm::system::VirtualMachine::setCommandNumber (int command) {
	commandNumber = command;
}

vm::system::MemoryState * vm::system::VirtualMachine::memoryStateToStop () {
	return m_memoryStateToStop;
}

void vm::system::VirtualMachine::setMemoryStateToStop (vm::system::MemoryState *ms) {
	m_memoryStateToStop = ms;
}
