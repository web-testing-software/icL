#ifndef icL_memory_Memory
#define icL_memory_Memory

#include "../structures/functioncontainer.h"
#include "memorystate.h"
#include "stackstate.h"

/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- @namespace memory
 */
namespace icL::memory {

class Memory
{
public:
	Memory();

	MemoryStateIt &     stateIt();
	StackStateIt &      stackIt();
	FunctionContainer & functions();

private:
	MemoryStateIt     m_stateIt;
	StackStateIt      m_stackIt;
	FunctionContainer m_functions;
};

}  // namespace icL::memory

#endif  // icL_memory_Memory
