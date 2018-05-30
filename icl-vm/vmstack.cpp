#include "vmstack.h"


namespace icL {

memory::Memory * VMStack::memory() {
	return &mem;
}

void VMStack::interrupt(
  memory::FunctionCall fcall, std::function<void(memory::Return &)> feedback) {
	//
}

const QString & VMStack::getWorkingDir() {
	//
}

const QString & VMStack::getCrossfirePass() {
	//
}

}  // namespace icL
