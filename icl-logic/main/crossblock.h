#ifndef CROSSBLOCK_H
#define CROSSBLOCK_H

#include "logicblock.h"



namespace vm::logic {

/**
 * @brief The CrossBlock class - this is a block with 2 children (LogicBlock* type)
 */
class CrossBlock : public LogicBlock
{
public:
	CrossBlock ();

	bool canAcceptBlock ();
	virtual void giveBlock (LogicBlock *block);

protected:
	LogicBlock *block1	= nullptr;
	LogicBlock *block2	= nullptr;
	bool value1			= false,
		 value2			= false,
		 value1getted	= false,
		 value2getted	= false;


	// LogicBlock interface
public:
	bool isCross () override;
	bool checkIntegrity () override;
	void resetResultValue () override;

	bool needCast() override;
	LogicBlock *castNow() override;
	bool step() override;
};

}

#endif // CROSSBLOCK_H
