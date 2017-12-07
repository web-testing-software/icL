#ifndef SINGLEBLOCK_H
#define SINGLEBLOCK_H

#include "../main/richblock.h"


namespace vm::main::logic::rich {


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

}
#endif // SINGLEBLOCK_H
