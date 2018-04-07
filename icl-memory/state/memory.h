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

	MemoryStateIt stateIt() const;
	StackStateIt stackIt() const;
	FunctionContainer functions() const;

private:
	MemoryStateIt m_stateIt;
	StackStateIt m_stackIt;
	FunctionContainer m_functions;
};

}

#endif // MEMORY_H
