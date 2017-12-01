#ifndef DATA_CONTAINER_H
#define DATA_CONTAINER_H

#include "memorystate.h"
#include "stackstate.h"

#include <QObject>

namespace vm {

enum class Error {
	COMMAND_NOT_FOUND,
	COMMAND_EXECUTION_ERROR,
	INVALID_ARGUMENTS,
	UNEXPECTED_EOF,
	DATA_CONVERSION_ERROR,
	WRONG_STACK_STATE,
	SERVER_ERROR,
	FILE_NOT_OPENED,
	WRONG_FILE_FORMAT,
	NO_VM_ERROR
};

namespace memory {

class DataContainer : public QObject
{
	Q_OBJECT

public:
	explicit DataContainer (QObject *parent = nullptr);

	// External access to functions
	MemoryStateIterator* memoryStateIt ();
	StackStateIterator* stackStateIt ();

	// interface for VM
	bool containsVar (const QString &name);
	bool checkType (const QString &name, DataState::Type &type);
	QVariant getVar (const QString &name);
	void setVar (const QString &name, QVariant &value, bool to_stack);

	void setError (Error m_error, const QString &description = "");

	// `Loop current` mode helper functions
	MemoryState* memoryStateToStop ();
	void setMemoryStateToStop (MemoryState *ms);

signals:

public slots:

private:
	MemoryStateIterator m_memoryStateIt;
	StackStateIterator m_stackStateIt;
	MemoryState *m_memoryStateToStop;

	Error m_error;
	QString last_error;
};

}   // system
}   // vm

#endif // DATA_CONTAINER_H
