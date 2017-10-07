#ifndef STRINGBLOCK_H
#define STRINGBLOCK_H

#include "../main/richblock.h"



namespace vm {
namespace system {
namespace logic {
namespace rich {

class StringBlock : public RichBlock
{
public:
	StringBlock (OperationType otype);

	// LogicBlock interface
	bool getResult () override;
};

}   // namespace rich
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // STRINGBLOCK_H
