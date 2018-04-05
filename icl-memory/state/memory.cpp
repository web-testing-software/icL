#include "memory.h"

namespace vm::memory {

Memory::Memory () {

}

MemoryStateIterator Memory::stateIt () const {
	return m_stateIt;
}

StackStateIterator Memory::stackIt () const {
	return m_stackIt;
}

FunctionContainer Memory::functions () const {
	return m_functions;
}

}
