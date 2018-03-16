#ifndef CROSSBLOCK_H
#define CROSSBLOCK_H

#include "logicblock.h"



namespace vm::main::logic {

/**
 * @brief The CrossBlock class - this is a block with 2 children (LogicBlock* type)
 */
class CrossBlock : public LogicBlock
{
public:
	CrossBlock ();

	bool canAcceptBlock ();
	virtual void giveBlock (LogicBlock *block);

	// LogicBlock interface
	bool isCross () override;
	bool checkIntegrity () override;
	void resetResultValue () override;

protected:
	LogicBlock *block1;
	LogicBlock *block2;
};

}

#endif // CROSSBLOCK_H
