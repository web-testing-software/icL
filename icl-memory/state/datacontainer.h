#ifndef DATA_CONTAINER_H
#define DATA_CONTAINER_H

#include "memorystate.h"
#include "stackstate.h"

#include "icl-vm/vm_errors.h"

#include <QObject>

namespace vm::memory {

/**
 * @brief The DataContainer class - contains ``data state` and `stack state`
 */
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
	void test();

signals:

public slots:

private:
	MemoryStateIterator m_memoryStateIt;
	StackStateIterator m_stackStateIt;
	MemoryState *m_memoryStateToStop;

	QString last_error;
	Error m_error;
};

}

#endif // DATA_CONTAINER_H
