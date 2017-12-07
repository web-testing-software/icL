#ifndef ORBLOCK_H
#define ORBLOCK_H

#include "../main/crossblock.h"



namespace vm::main::logic::cross {

class OrBlock : public CrossBlock
{
public:
	OrBlock ();

	// LogicBlock interface
	bool calcResult () override;
};

}

#endif // ORBLOCK_H
