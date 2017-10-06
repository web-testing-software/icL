#include "virtualmachine.h"

vm::system::VirtualMachine::VirtualMachine () {

}

bool vm::system::VirtualMachine::containsVar(const QString &name)
{
	return memoryState->contains (name) || m_statackStateIt.contains (name);
}
