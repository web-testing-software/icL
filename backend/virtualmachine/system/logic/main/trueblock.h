#ifndef TRUEBLOCK_H
#define TRUEBLOCK_H

#include "logicblock.h"



namespace vm {
namespace system {
namespace logic {

class TrueBlock : public LogicBlock
{
public:
	TrueBlock ();

	// LogicBlock interface
public:
	bool calcResult () override;
	bool isCross () override;
};

}   // namespace logic
}   // namespace sytem
}   // namespace vm

#endif // TRUEBLOCK_H
