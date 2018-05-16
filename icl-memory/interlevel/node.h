#ifndef NODE_H
#define NODE_H

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

#endif  // NODE_H
