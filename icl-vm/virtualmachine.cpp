#include "virtualmachine.h"

#include "virtualmachinestack.h"


namespace icL {

VirtualMachine::VirtualMachine(VirtualMachineStack * vms)
	: interpreter({&il, vms->source()}) {

	// Initialize interlevel object
	il.mem = vms->memory();
	il.inter = &interpreter;
	il.vm = this;
	il.vms = vms;
}

}  // namespace icL
