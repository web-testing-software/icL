#ifndef STRINGLISTSTRINGBLOCK_H
#define STRINGLISTSTRINGBLOCK_H

#include "../main/richblock.h"

namespace vm {
namespace system {
namespace logic {
namespace rich {

class StringListStringBlock : public RichBlock
{
public:
	StringListStringBlock(OperationType otype);
};

} // namespace rich
} // namespace logic
} // namespace system
} // namespace vm

#endif // STRINGLISTSTRINGBLOCK_H
