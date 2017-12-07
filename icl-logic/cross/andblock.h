#ifndef ANDBLOCK_H
#define ANDBLOCK_H

#include "../main/crossblock.h"



namespace vm::main::logic::cross {

class AndBlock : public CrossBlock
{
public:
	AndBlock ();

	// LogicBlock interface
	bool calcResult () override;
};

}

#endif // ANDBLOCK_H
