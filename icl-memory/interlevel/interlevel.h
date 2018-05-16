#ifndef INTERLEVEL_H
#define INTERLEVEL_H

#include "interfaces.h"


namespace icL::memory::interlevel {

struct InterLevel {
	Interpreteur *inter;
	VirtualMachine *vm;
	VirtualMachineStack *vms;
	Server *server;
};

}


#endif // INTERLEVEL_H
