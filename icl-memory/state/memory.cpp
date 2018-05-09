#include "memory.h"

namespace vm::memory {

Memory::Memory () {

}

MemoryStateIt &Memory::stateIt() {
	return m_stateIt;
}

StackStateIt &Memory::stackIt() {
	return m_stackIt;
}

FunctionContainer &Memory::functions() {
	return m_functions;
}

}
