#ifndef IFSTACKSTATE_H
#define IFSTACKSTATE_H

#include "icl-logic/main/logicblock.h"
#include "icl-memory/state/stackstate.h"




namespace vm::memory {

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

}

#endif // IFSTACKSTATE_H
