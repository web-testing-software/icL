#ifndef IFSTACKSTATE_H
#define IFSTACKSTATE_H

#include "main/logicblock.h"
#include "state/stackstate.h"




namespace vm {
namespace memory {

class IfStackState : public StackState
{
public:
	IfStackState(StackState *prev, int stackLevel);

	// StackState interface
	bool tryToDestroy() override;
	void releaseCondition() override;

protected:
	main::logic::LogicBlock* logicBlock;
};

} // namespace system
} // namespace vm

#endif // IFSTACKSTATE_H
