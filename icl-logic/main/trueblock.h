#ifndef TRUEBLOCK_H
#define TRUEBLOCK_H

#include "logicblock.h"



namespace vm::main::logic {

class TrueBlock : public LogicBlock
{
public:
	TrueBlock ();

	// LogicBlock interface
public:
	bool calcResult () override;
	bool isCross () override;
};

}

#endif // TRUEBLOCK_H
