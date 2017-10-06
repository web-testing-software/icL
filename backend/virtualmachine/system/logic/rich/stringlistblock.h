#ifndef STRINGLISTBLOCK_H
#define STRINGLISTBLOCK_H

#include "../main/richblock.h"



namespace vm {
namespace system {
namespace logic {
namespace rich {

class StringListBlock : public RichBlock
{
public:
	StringListBlock (OperationType otype);

	// LogicBlock interface
	bool getResult() override;
};

}   // namespace rich
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // STRINGLISTBLOCK_H
