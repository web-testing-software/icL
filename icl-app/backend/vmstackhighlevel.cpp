//#include "vmstackhighlevel.h"

//#include "serverhighlevel.h"

//#include <icl-vm/virtualmachine.h>
//#include <icl-vm/vmstack.cpp>

//namespace icL::app {

//void VMStackHighLevel::init(const QString & source, bool contentChanged) {
//	if (vm == nullptr || contentChanged) {
//		this->source = source;

//		if (vm == nullptr) {
//			vm = new VirtualMachine(this, nullptr, &this->source);
//		}
//	}
//}

//void VMStackHighLevel::step(StepTypeHighLevel::Value stopRule) {
//	memory::StepType::Value returned;

//	do {
//		returned = vm->step();

//		if (returned == memory::StepType::NONE) {
//			VirtualMachine * nvm = vm->getParent();

//			delete vm;
//			vm = nvm;
//		}

//		returned = memory::StepType::COMMAND_OUT;

//	} while ((returned & stopRule) == 0x0);
//}

//void VMStackHighLevel::highlight(int pos1, int pos2) {
//	emit requestHighlight(pos1, pos2);
//}

//// For QML
//ServerHighLevel * VMStackHighLevel::server() const {
//	return m_server;
//}

//// For C++
//Server * VMStackHighLevel::serverMiddleLevel() const {
//	return m_server;
//}

//void VMStackHighLevel::setServer(ServerHighLevel * server) {
//	if (m_server == server)
//		return;

//	m_server = server;
//	emit serverChanged(server);
//}

//}  // namespace icL::app
