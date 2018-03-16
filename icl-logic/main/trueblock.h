#ifndef TRUEBLOCK_H
#define TRUEBLOCK_H

#include "logicblock.h"



namespace vm::main::logic {

/**
 * @brief The TrueBlock class - true contant
 */
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
