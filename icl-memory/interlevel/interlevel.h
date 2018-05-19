#ifndef icL_memory_InterLevel
#define icL_memory_InterLevel

#include "../state/memory.h"
#include "interfaces.h"


namespace icL::memory {

struct InterLevel
{
	memory::Memory *      mem;
	Interpreteur *        inter;
	VirtualMachine *      vm;
	VirtualMachineStack * vms;
	Server *              server;
};

}  // namespace icL::memory


#endif  // icL_memory_InterLevel
