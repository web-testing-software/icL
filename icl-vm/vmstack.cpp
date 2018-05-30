#include "vmstack.h"

#include "virtualmachine.h"

namespace icL {

VMStack::VMStack() {}

memory::Memory * VMStack::memory() {
	return &mem;
}


void VMStack::init(const QString & source, bool contentChanged) {
	if (vm == nullptr || contentChanged) {
		this->source = source;

		if (vm == nullptr) {
			vm = new VirtualMachine(this, nullptr, &this->source);

			vm->setFragLimits(0, source.size());
		}
	}
}

void VMStack::step(int stopRule) {
	memory::StepType::Value returned;

	do {
		returned = vm->step();

		if (returned == memory::StepType::NONE) {
			VirtualMachine * nvm = vm->getParent();

			delete vm;
			vm = nvm;
		}

		returned = memory::StepType::COMMAND_OUT;

	} while ((returned & stopRule) == 0x0);
}

Server * VMStack::server() const {
	return m_server;
}

void VMStack::interrupt(
  memory::FunctionCall fcall, std::function<void(memory::Return &)> feedback) {}

const QString & VMStack::getWorkingDir() {}

const QString & VMStack::getCrossfirePass() {}

void VMStack::highlight(int pos1, int pos2) {
	emit requestHighlight(pos1, pos2);
}


void VMStack::setServer(Server * server) {
	if (m_server == server)
		return;

	m_server = server;
	emit serverChanged(m_server);
}

}  // namespace icL
