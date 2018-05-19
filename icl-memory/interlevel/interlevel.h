#ifndef INTERLEVEL_H
#define INTERLEVEL_H

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


#endif  // INTERLEVEL_H
