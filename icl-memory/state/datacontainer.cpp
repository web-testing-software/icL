#include "datacontainer.h"

namespace vm::memory {

DataContainer::DataContainer (QObject *parent)
	: QObject (parent) {

}

MemoryStateIterator * DataContainer::memoryStateIt () {
	return &m_memoryStateIt;
}

StackStateIterator * DataContainer::stackStateIt () {
	return &m_stackStateIt;
}

bool DataContainer::containsVar (const QString &name) {
	return m_memoryStateIt.state ()->contains (name)
		   || m_stackStateIt.contains (name);
}

bool DataContainer::checkType (const QString &name, DataState::Type &type) {
	return m_memoryStateIt.state ()->checkType (name, type)
		   || m_stackStateIt.checkType (name, type);
}

QVariant DataContainer::getVar (const QString &name) {
	if (m_memoryStateIt.state ()->contains (name)) {
		return m_memoryStateIt.state ()->getValue (name);
	}
	else {
		return m_stackStateIt.getValue (name);
	}
}

void DataContainer::setVar (const QString &name, QVariant &value, bool to_stack) {
	//
}

void DataContainer::setError (vm::Error m_error, const QString &description) {
	this->m_error		= m_error;
	this->last_error	= description;
}

MemoryState * DataContainer::memoryStateToStop () {
	return m_memoryStateToStop;
}

void DataContainer::setMemoryStateToStop (MemoryState *ms) {
	m_memoryStateToStop = ms;
}

}
