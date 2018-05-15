#include "memory.h"

namespace icL::memory {

Memory::Memory() {}

MemoryStateIt & Memory::stateIt() {
	return m_stateIt;
}

StackStateIt & Memory::stackIt() {
	return m_stackIt;
}

FunctionContainer & Memory::functions() {
	return m_functions;
}

}  // namespace icL::memory
