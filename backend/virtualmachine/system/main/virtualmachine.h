#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

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
public:
	VirtualMachine ();

	MemoryStateIterator*  memoryStateIt ();
	StackStateIterator* stackStateIt ();

	static VirtualMachine* instance ();

	bool containsVar (const QString &name);

private:
	MemoryStateIterator m_memoryStateIt;
	StackStateIterator m_statackStateIt;
};

}
}

#endif // VIRTUALMACHINE_H
