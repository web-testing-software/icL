#ifndef MEMORY_H
#define MEMORY_H

#include "../structures/functioncontainer.h"
#include "memorystate.h"
#include "stackstate.h"


namespace vm::memory {

class Memory
{
public:
	Memory();

	MemoryStateIt&     stateIt();
	StackStateIt&      stackIt();
	FunctionContainer& functions();

private:
	MemoryStateIt     m_stateIt;
	StackStateIt      m_stackIt;
	FunctionContainer m_functions;
};

}  // namespace vm::memory

#endif  // MEMORY_H
