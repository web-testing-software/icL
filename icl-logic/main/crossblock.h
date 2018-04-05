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
	virtual void canResultPreliminarily() = 0;

	// LogicBlock interface
	bool isCross () override;
	bool checkIntegrity () override;
	void resetResultValue () override;

protected:
	LogicBlock *block1	= nullptr;
	LogicBlock *block2	= nullptr;
	bool value1			= false,
		 value2			= false,
		 value1getted	= false,
		 value2getted	= false;
};

}

#endif // CROSSBLOCK_H
