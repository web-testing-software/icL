#include "datacontainer.h"

namespace vm::memory {

DataContainer::DataContainer (QObject *parent)
	: QObject (parent) {

}

/**
 * @brief DataContainer::memoryStateIt
 * @return a memory state iterator
 */
MemoryStateIterator * DataContainer::memoryStateIt () {
	return &m_memoryStateIt;
}

/**
 * @brief DataContainer::stackStateIt
 * @return a stack state iterator
 */
StackStateIterator * DataContainer::stackStateIt () {
	return &m_stackStateIt;
}

/**
 * @brief DataContainer::containsVar
 * @param name - the name of the variable
 * @return the stack state or the memory stack contains the variable
 */
bool DataContainer::containsVar (const QString &name) {
	return m_memoryStateIt.state ()->contains (name)
		   || m_stackStateIt.contains (name);
}

/**
 * @brief DataContainer::checkType
 * @param name - the name of the variable
 * @param type - variable type
 * @return the type of variable is matching
 */
bool DataContainer::checkType (const QString &name, DataState::Type &type) {
	return m_memoryStateIt.state ()->checkType (name, type)
		   || m_stackStateIt.checkType (name, type);
}

/**
 * @brief DataContainer::getVar
 * @param name - the name of variable
 * @return variable value
 */
QVariant DataContainer::getVar (const QString &name) {
	if (m_memoryStateIt.state ()->contains (name)) {
		return m_memoryStateIt.state ()->getValue (name);
	}
	else {
		return m_stackStateIt.getValue (name);
	}
}

/**
 * @brief DataContainer::setVar
 * @param name - the name of the value
 * @param value - the value to set
 * @param to_stack - stack state or memory state
 */
void DataContainer::setVar (const QString &name, QVariant &value, bool to_stack) {
	//
}

/**
 * @brief DataContainer::setError
 * @param m_error - error id
 * @param description - additional data
 */
void DataContainer::setError (vm::Error m_error, const QString &description) {
	this->m_error		= m_error;
	this->last_error	= description;
}

/**
 * @brief DataContainer::memoryStateToStop
 * @return memory state to stop step execution
 */
MemoryState * DataContainer::memoryStateToStop () {
	return m_memoryStateToStop;
}

/**
 * @brief DataContainer::setMemoryStateToStop
 * @param ms - memory state to stop step execution
 */
void DataContainer::setMemoryStateToStop (MemoryState *ms) {
	m_memoryStateToStop = ms;
}

}
