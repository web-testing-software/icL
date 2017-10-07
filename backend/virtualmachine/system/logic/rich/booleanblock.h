#ifndef BOOLEANBLOCK_H
#define BOOLEANBLOCK_H

#include "../main/richblock.h"



namespace vm {
namespace system {
namespace logic {
namespace rich {

class BooleanBlock : public RichBlock
{
public:
	BooleanBlock (OperationType otype);

	// LogicBlock interface
	bool getResult () override;
};

}   // namespace rich
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // BOOLEANBLOCK_H
