#ifndef CROSSBLOCK_H
#define CROSSBLOCK_H

#include "logicblock.h"



namespace vm {
namespace system {
namespace logic {

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
}
}

#endif // CROSSBLOCK_H
