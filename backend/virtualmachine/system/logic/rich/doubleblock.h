#ifndef DOUBLEBLOCK_H
#define DOUBLEBLOCK_H

#include "../main/richblock.h"



namespace vm {
namespace system {
namespace logic {
namespace rich {

class DoubleBlock : public RichBlock
{
public:
	DoubleBlock (OperationType otype);

	// LogicBlock interface
	bool getResult() override;
};

}   // namespace rich
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // DOUBLEBLOCK_H
