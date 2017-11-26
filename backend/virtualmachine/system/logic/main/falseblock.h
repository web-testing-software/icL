#ifndef FALSEBLOCK_H
#define FALSEBLOCK_H

#include "logicblock.h"



namespace vm {
namespace main {
namespace logic {

class FalseBlock : public LogicBlock
{
public:
	FalseBlock ();

	// LogicBlock interface
public:
	bool calcResult () override;
	bool isCross () override;
};

}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // FALSEBLOCK_H
