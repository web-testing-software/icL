#ifndef FALSEBLOCK_H
#define FALSEBLOCK_H

#include "logicblock.h"



namespace vm::main::logic {

/**
 * @brief The FalseBlock class - false constant
 */
class FalseBlock : public LogicBlock
{
public:
	FalseBlock ();

	// LogicBlock interface
public:
	bool calcResult () override;
	bool isCross () override;
};

}

#endif // FALSEBLOCK_H
