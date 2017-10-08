#ifndef IFSTACKSTATE_H
#define IFSTACKSTATE_H

#include "../logic/main/logicblock.h"
#include "stackstate.h"




namespace vm {
namespace system {

class IfStackState : public StackState
{
public:
	IfStackState(StackState *prev, int stackLevel);

	// StackState interface
	bool tryToDestroy() override;
	void releaseCondition() override;

protected:
	logic::LogicBlock* logicBlock;
};

} // namespace system
} // namespace vm

#endif // IFSTACKSTATE_H
