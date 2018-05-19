#ifndef icL_memory_Node
#define icL_memory_Node

#include "interlevel.h"


namespace icL::memory {

class Node
{
public:
	Node(memory::InterLevel * il)
		: il(il) {}

protected:
	memory::InterLevel * il;
};

}  // namespace icL::memory

#endif  // icL_memory_Node
