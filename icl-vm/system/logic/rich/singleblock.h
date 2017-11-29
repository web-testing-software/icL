#ifndef SINGLEBLOCK_H
#define SINGLEBLOCK_H

#include "../main/richblock.h"


namespace vm {
namespace main {
namespace logic {
namespace rich {


class SingleBlock : public RichBlock
{
public:
	SingleBlock(OperationType otype);

	// LogicBlock interface
public:
	bool checkIntegrity() override;

protected:
	bool calcResult() override;
};

}   // namespace rich
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // SINGLEBLOCK_H
