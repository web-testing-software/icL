#ifndef INTBLOCK_H
#define INTBLOCK_H

#include "../main/richblock.h"



namespace vm {
namespace system {
namespace logic {
namespace rich {

class IntBlock : public RichBlock
{
public:
	IntBlock (OperationType otype);

	// LogicBlock interface
	bool getResult () override;
};

}   // namespace rich
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // INTBLOCK_H
