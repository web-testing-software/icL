#include "memory.h"

namespace vm::memory {

Memory::Memory () {

}

MemoryStateIt Memory::stateIt () const {
	return m_stateIt;
}

StackStateIt Memory::stackIt () const {
	return m_stackIt;
}

FunctionContainer Memory::functions () const {
	return m_functions;
}

}
