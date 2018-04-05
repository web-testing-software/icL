#ifndef MEMORY_H
#define MEMORY_H

#include "memorystate.h"
#include "stackstate.h"
#include "../structures/functioncontainer.h"


namespace vm::memory {

class Memory
{
public:
	Memory();

	MemoryStateIterator stateIt() const;
	StackStateIterator stackIt() const;
	FunctionContainer functions() const;

private:
	MemoryStateIterator m_stateIt;
	StackStateIterator m_stackIt;
	FunctionContainer m_functions;
};

}

#endif // MEMORY_H
