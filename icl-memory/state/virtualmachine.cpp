//#include "virtualmachine.h"

//vm::main::VirtualMachine *vm::main::VirtualMachine::m_instance = nullptr;

//vm::main::VirtualMachine::VirtualMachine () {
//	if (m_instance == nullptr) {
//		m_instance = this;
//	}
//	m_inStream.setVersion (QDataStream::Qt_5_6);
//	m_inStream.setFloatingPointPrecision (QDataStream::DoublePrecision);
//	m_inStream.setDevice (&m_inFile);
//	m_outStream.setVersion (QDataStream::Qt_5_6);
//	m_outStream.setFloatingPointPrecision (QDataStream::DoublePrecision);
//	m_outStream.setDevice (&m_outFile);
//}

//vm::main::MemoryStateIterator * vm::main::VirtualMachine::memoryStateIt () {
//	return &m_memoryStateIt;
//}

//vm::main::StackStateIterator * vm::main::VirtualMachine::stackStateIt () {
//	return &m_stackStateIt;
//}

//void vm::main::VirtualMachine::makeCurrent (vm::main::VirtualMachine *vm) {
//	m_instance = vm;
//}

//vm::main::VirtualMachine * vm::main::VirtualMachine::instance () {
//	return m_instance;
//}

//void vm::main::VirtualMachine::openFile (const QString &path) {
//	m_inFile.setFileName (path);
//	m_inFile.open (QFile::ReadOnly);
//}

//bool vm::main::VirtualMachine::containsVar (const QString &name) {
//	return memoryState->contains (name) || m_stackStateIt.contains (name);
//}

//bool vm::main::VirtualMachine::checkType (const QString &name, vm::main::DataState::Type &type) {
//	return memoryState->checkType (name, type) || m_stackStateIt.checkType (name, type);
//}

//QVariant vm::main::VirtualMachine::getVar (const QString &name) {
//	if (memoryState->contains (name)) {
//		return memoryState->getValue (name);
//	}
//	else {
//		return m_stackStateIt.getValue (name);
//	}
//}

//void vm::main::VirtualMachine::search (const vm::main::CommandsToSearch &commands) {
//	m_searchedCommands	= commands;
//	m_runIsPermited		= false;
//}

//bool vm::main::VirtualMachine::runIsPermited () {
//	return m_runIsPermited;
//}


//void vm::main::VirtualMachine::setError (vm::Error error, const QString &description) {
//	this->m_error		= error;
//	this->last_error	= description;
//}

//void vm::main::VirtualMachine::setStepNumber (int step) {
//	m_stepNumber = step;
//}

//void vm::main::VirtualMachine::setCommandNumber (int command) {
//	m_commandNumber = command;
//}

//vm::main::MemoryState * vm::main::VirtualMachine::memoryStateToStop () {
//	return m_memoryStateToStop;
//}

//void vm::main::VirtualMachine::setMemoryStateToStop (vm::main::MemoryState *ms) {
//	m_memoryStateToStop = ms;
//}

//QDataStream * vm::main::VirtualMachine::getInStream () {
//	return &m_inStream;
//}

//QDataStream * vm::main::VirtualMachine::getOutStream () {
//	return &m_outStream;
//}

//void vm::main::VirtualMachine::run () {
//	unsigned int code;

//	if (!m_inFile.isOpen ()) {
//		setError (Error::FILE_NOT_OPENED);
//		return;
//	}
//	inStream >> code;

//	if (code != 0xFA57C0DE) {
//		setError (Error::WRONG_FILE_FORMAT);
//		return;
//	}

//	m_stackStateIt.clear ();
//	m_stackStateIt.openNewStack (StackState::StackType::COMMOM_STACK);
//	m_memoryStateIt.clear ();
//	m_memoryStateIt.appendNewAfter ();

//	int command;

//	while (!m_inStream.atEnd () && m_error == Error::NO_VM_ERROR) {
//		m_inStream >> command;

//		if (command == -1) {
//			m_stackStateIt.closeStack ();

//			if (m_stackStateIt.stack () == nullptr && !m_inStream.atEnd ()) {
//				m_error = Error::UNEXPECTED_EOF;
//			}
//		}
//		else {
////			parse (command);

//			if (!m_runIsPermited) {
//				if (command == m_searchedCommands.command1 || command == m_searchedCommands.command2) {
//					m_searchedCommands	= CommandsToSearch ();
//					m_runIsPermited		= true;
//				}
//			}
//		}
//	}

//	if (command != -1 && m_error == Error::NO_VM_ERROR) {
//		m_error = Error::UNEXPECTED_EOF;
//	}
//}
