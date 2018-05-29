#include "virtualmachinestack.h"

#include "virtualmachine.h"

namespace icL {

VirtualMachineStack::VirtualMachineStack() {}


void VirtualMachineStack::init(const QString & source, bool contentChanged) {
	if (vm == nullptr || contentChanged) {
		this->source = source;

		if (vm == nullptr) {
			vm = new VirtualMachine(this, nullptr, &this->source);
		}
	}
}

void VirtualMachineStack::step(memory::StepType::Value stopRule) {
	memory::StepType::Value returned;

	do {
		returned = vm->step();

		if (returned == memory::StepType::None) {
			VirtualMachine * nvm = vm->getParent();

			delete vm;
			vm = nvm;
		}

		returned = memory::StepType::CommandOut;

	} while ((returned & stopRule) == 0x0);
}

Server * VirtualMachineStack::server() const {
	return m_server;
}

void VirtualMachineStack::highlight(int pos1, int pos2) {
	emit requestHighlight(pos1, pos2);
}


void VirtualMachineStack::setServer(Server * server) {
	if (m_server == server)
		return;

	m_server = server;
	emit serverChanged(m_server);
}

}  // namespace icL
