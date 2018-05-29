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
 *  '-> memory
 */
namespace icL::memory {

class Memory
{
public:
	Memory();

	MemoryStateIt &      stateIt();
	StackStateIt &       stackIt();
	FunctionContainer &  functions();
	QMap<QString, int> & signal_s(); // signals is keyword

private:
	MemoryStateIt     m_stateIt;
	StackStateIt      m_stackIt;
	FunctionContainer m_functions;

	QMap<QString, int> m_signals = {{{"UnrealCase", -1},
									 {"StringParse", -2},
									 {"EmptyList", -3},
									 {"MultipleValues", -4},
									 {"NullElement", -5},
									 {"NotVisible", -6},
									 {"WrongName", -7},
									 {"OutOfBounds", -8},
									 {"OutOfScreen", -9},
									 {"FileNotFound", -10}}};
};

}  // namespace icL::memory

#endif  // icL_memory_Memory
