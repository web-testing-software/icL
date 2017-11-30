#include "../../parser.h"
#include "driver.h"

const QStringList keywoords = {
	//
};

vm::main::Driver::Driver (QObject *parent)
	: QObject (parent) {

}

vm::main::Server * vm::main::Driver::server () {
	return &m_server;
}

vm::main::MemoryStateIterator * vm::main::Driver::memoryStateIt () {
	return &m_memoryStateIt;
}

vm::main::StackStateIterator * vm::main::Driver::stackStateIt () {
	return &m_stackStateIt;
}

void vm::main::Driver::openFile (const QString &path) {

}

bool vm::main::Driver::containsVar (const QString &name) {
	return m_memoryStateIt.state ()->contains (name)
		   || m_stackStateIt.contains (name);
}

bool vm::main::Driver::checkType (const QString &name, vm::main::DataState::Type &type) {
	return m_memoryStateIt.state ()->checkType (name, type)
		   || m_stackStateIt.checkType (name, type);
}

QVariant vm::main::Driver::getVar (const QString &name) {
	if (m_memoryStateIt.state ()->contains (name)) {
		return m_memoryStateIt.state ()->getValue (name);
	}
	else {
		return m_stackStateIt.getValue (name);
	}
}

void vm::main::Driver::setVar(const QString &name, QVariant &value, bool to_stack)
{
	//
}

void vm::main::Driver::setError (vm::Error m_error, const QString &description) {
	this->m_error		= m_error;
	this->last_error	= description;
}

vm::main::MemoryState * vm::main::Driver::memoryStateToStop () {
	return m_memoryStateToStop;
}

void vm::main::Driver::setMemoryStateToStop (vm::main::MemoryState *ms) {
	m_memoryStateToStop = ms;
}

int vm::main::Driver::currentCommand () {
	return m_currentCommand;
}

const QVariantMap * vm::main::Driver::currentParams () {
	return &m_currentParams;
}

void vm::main::Driver::setCurrentCommand (int n_currentCommand) {
	m_currentCommand = n_currentCommand;
}

void vm::main::Driver::setCurrentParams (const QVariantMap &n_currentParams) {
	m_currentParams.clear ();
	m_currentParams = n_currentParams;
}
