#ifndef NOTBLOCK_H
#define NOTBLOCK_H

#include "../main/crossblock.h"



namespace vm::main::logic::cross {

class NotBlock : public CrossBlock
{
public:
	NotBlock ();

	// LogicBlock interface
	bool calcResult () override;
	bool checkIntegrity () override;
	void resetResultValue () override;
};

}

#endif // NOTBLOCK_H
