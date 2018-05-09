#ifndef XORBLOCK_H
#define XORBLOCK_H

#include "../main/crossblock.h"



namespace vm::logic::cross {

/**
 * @brief The XOrBlock class - ^^
 */
class XOrBlock : public CrossBlock
{
public:
	XOrBlock ();

	// LogicBlock interface
	bool calcResult () override;
};

}

#endif // XORBLOCK_H