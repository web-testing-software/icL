#ifndef icL_memory_InterLevel
#define icL_memory_InterLevel

#include "../state/memory.h"
#include "interfaces.h"

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

struct InterLevel
{
	memory::Memory *      mem;
	Interpreter *        inter;
	VirtualMachine *      vm;
	VirtualMachineStack * vms;
	Server *              server;
};

}  // namespace icL::memory


#endif  // icL_memory_InterLevel
