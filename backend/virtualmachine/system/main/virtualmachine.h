#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include "../../parser.h"
#include "memorystate.h"
#include "stackstate.h"

// Fast access to main active objects
#define virtualMachine vm::system::VirtualMachine::instance ()
#define stackStateIterator virtualMachine->stackStateIt ()
#define stackState stackStateIterator->stack ()
#define memoryStateIterator virtualMachine->memoryStateIt ()
#define memoryState memoryStateIterator->state ()

namespace vm {
namespace system {


class VirtualMachine
{
	static VirtualMachine *m_instance;

public:
	enum class WorkMode {
		EXECUTING,
		SHOWING_ON_SCREEN
	};

	VirtualMachine ();

	// External access to functions
	MemoryStateIterator* memoryStateIt ();
	StackStateIterator* stackStateIt ();

	static VirtualMachine* instance ();

	// Base functions
	void openFile (const QString &path);
	bool containsVar (const QString &name);

	// Debug functions
	void setError (vm::Error error);
	void setStepNumber (int step);
	void setCommandNumber (int command);

	// `Loop current` mode helper functions
	MemoryState* memoryStateToStop ();
	void setMemoryStateToStop (MemoryState* ms);

private:
	MemoryStateIterator m_memoryStateIt;
	StackStateIterator m_stackStateIt;
	MemoryState* m_memoryStateToStop;

	QFile inFile;
	vm::Error error;
	int stepNumber = 0;
	int commandNumber = 0;
};

}
}

#endif // VIRTUALMACHINE_H
