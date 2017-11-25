#include "virtualmachine.h"

vm::system::VirtualMachine *vm::system::VirtualMachine::m_instance = nullptr;

vm::system::VirtualMachine::VirtualMachine () {
	if (m_instance == nullptr) {
		m_instance = this;
	}
	m_inStream.setVersion (QDataStream::Qt_5_6);
	m_inStream.setFloatingPointPrecision (QDataStream::DoublePrecision);
	m_inStream.setDevice (&m_inFile);
	m_outStream.setVersion (QDataStream::Qt_5_6);
	m_outStream.setFloatingPointPrecision (QDataStream::DoublePrecision);
	m_outStream.setDevice (&m_outFile);
}

vm::system::MemoryStateIterator * vm::system::VirtualMachine::memoryStateIt () {
	return &m_memoryStateIt;
}

vm::system::StackStateIterator * vm::system::VirtualMachine::stackStateIt () {
	return &m_stackStateIt;
}

void vm::system::VirtualMachine::makeCurrent (vm::system::VirtualMachine *vm) {
	m_instance = vm;
}

vm::system::VirtualMachine * vm::system::VirtualMachine::instance () {
	return m_instance;
}

void vm::system::VirtualMachine::openFile (const QString &path) {
	m_inFile.setFileName (path);
	m_inFile.open (QFile::ReadOnly);
}

bool vm::system::VirtualMachine::containsVar (const QString &name) {
	return memoryState->contains (name) || m_stackStateIt.contains (name);
}

bool vm::system::VirtualMachine::checkType (const QString &name, vm::system::DataState::Type &type) {
	return memoryState->checkType (name, type) || m_stackStateIt.checkType (name, type);
}

QVariant vm::system::VirtualMachine::getVar (const QString &name) {
	if (memoryState->contains (name)) {
		return memoryState->getValue (name);
	}
	else {
		return m_stackStateIt.getValue (name);
	}
}

void vm::system::VirtualMachine::search (const vm::system::CommandsToSearch &commands) {
	m_searchedCommands	= commands;
	m_runIsPermited		= false;
}

bool vm::system::VirtualMachine::runIsPermited () {
	return m_runIsPermited;
}


void vm::system::VirtualMachine::setError (vm::Error error, const QString &description) {
	this->m_error		= error;
	this->last_error	= description;
}

void vm::system::VirtualMachine::setStepNumber (int step) {
	m_stepNumber = step;
}

void vm::system::VirtualMachine::setCommandNumber (int command) {
	m_commandNumber = command;
}

vm::system::MemoryState * vm::system::VirtualMachine::memoryStateToStop () {
	return m_memoryStateToStop;
}

void vm::system::VirtualMachine::setMemoryStateToStop (vm::system::MemoryState *ms) {
	m_memoryStateToStop = ms;
}

QDataStream * vm::system::VirtualMachine::getInStream () {
	return &m_inStream;
}

QDataStream * vm::system::VirtualMachine::getOutStream () {
	return &m_outStream;
}

void vm::system::VirtualMachine::run () {
	unsigned int code;

	if (!m_inFile.isOpen ()) {
		setError (Error::FILE_NOT_OPENED);
		return;
	}
	inStream >> code;

	if (code != 0xFA57C0DE) {
		setError (Error::WRONG_FILE_FORMAT);
		return;
	}

	m_stackStateIt.clear ();
	m_stackStateIt.openNewStack (StackState::StackType::COMMOM_STACK);
	m_memoryStateIt.clear ();
	m_memoryStateIt.appendNewAfter ();

	int command;

	while (!m_inStream.atEnd () && m_error == Error::NO_VM_ERROR) {
		m_inStream >> command;

		if (command == -1) {
			m_stackStateIt.closeStack ();

			if (m_stackStateIt.stack () == nullptr && !m_inStream.atEnd ()) {
				m_error = Error::UNEXPECTED_EOF;
			}
		}
		else {
//			parse (command);

			if (!m_runIsPermited) {
				if (command == m_searchedCommands.command1 || command == m_searchedCommands.command2) {
					m_searchedCommands	= CommandsToSearch ();
					m_runIsPermited		= true;
				}
			}
		}
	}

	if (command != -1 && m_error == Error::NO_VM_ERROR) {
		m_error = Error::UNEXPECTED_EOF;
	}
}
