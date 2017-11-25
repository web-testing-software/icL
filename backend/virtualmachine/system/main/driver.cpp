#include "driver.h"

vm::system::Driver::Driver (QObject *parent)
	: QObject (parent) {

}

vm::system::MemoryStateIterator * vm::system::Driver::memoryStateIt () {
	return &m_memoryStateIt;
}

vm::system::StackStateIterator * vm::system::Driver::stackStateIt () {
	return &m_stackStateIt;
}

void vm::system::Driver::openFile (const QString &path) {

}

bool vm::system::Driver::containsVar (const QString &name) {
	return memoryState->contains (name) || m_stackStateIt.contains (name);
}

bool vm::system::Driver::checkType (const QString &name, vm::system::DataState::Type &type) {
	return memoryState->checkType (name, type) || m_stackStateIt.checkType (name, type);
}

QVariant vm::system::Driver::getVar (const QString &name) {
	if (memoryState->contains (name)) {
		return memoryState->getValue (name);
	}
	else {
		return m_stackStateIt.getValue (name);
	}
}

void vm::system::Driver::setError (vm::Error m_error, const QString &description) {
	this->m_error		= m_error;
	this->last_error	= description;
}

vm::system::MemoryState * vm::system::Driver::memoryStateToStop () {
	return m_memoryStateToStop;
}

void vm::system::Driver::setMemoryStateToStop (vm::system::MemoryState *ms) {
	m_memoryStateToStop = ms;
}

int vm::system::Driver::currentCommand () {
	return m_currentCommand;
}

const QMap <QString, QVariant> * vm::system::Driver::currentParams () {
	return &m_currentParams;
}

void vm::system::Driver::setCurrentCommand (int n_currentCommand) {
	m_currentCommand = n_currentCommand;
}

void vm::system::Driver::setCurrentParams (const QMap <QString, QVariant> &n_currentParams) {
	m_currentParams.clear ();
	m_currentParams = n_currentParams;
}
