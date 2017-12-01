#include "datacontainer.h"

vm::memory::DataContainer::DataContainer (QObject *parent)
	: QObject (parent) {

}

vm::memory::MemoryStateIterator * vm::memory::DataContainer::memoryStateIt () {
	return &m_memoryStateIt;
}

vm::memory::StackStateIterator * vm::memory::DataContainer::stackStateIt () {
	return &m_stackStateIt;
}

bool vm::memory::DataContainer::containsVar (const QString &name) {
	return m_memoryStateIt.state ()->contains (name)
		   || m_stackStateIt.contains (name);
}

bool vm::memory::DataContainer::checkType (const QString &name, vm::memory::DataState::Type &type) {
	return m_memoryStateIt.state ()->checkType (name, type)
		   || m_stackStateIt.checkType (name, type);
}

QVariant vm::memory::DataContainer::getVar (const QString &name) {
	if (m_memoryStateIt.state ()->contains (name)) {
		return m_memoryStateIt.state ()->getValue (name);
	}
	else {
		return m_stackStateIt.getValue (name);
	}
}

void vm::memory::DataContainer::setVar(const QString &name, QVariant &value, bool to_stack)
{
	//
}

void vm::memory::DataContainer::setError (vm::Error m_error, const QString &description) {
	this->m_error		= m_error;
	this->last_error	= description;
}

vm::memory::MemoryState * vm::memory::DataContainer::memoryStateToStop () {
	return m_memoryStateToStop;
}

void vm::memory::DataContainer::setMemoryStateToStop (vm::memory::MemoryState *ms) {
	m_memoryStateToStop = ms;
}
