#ifndef ORBLOCK_H
#define ORBLOCK_H

#include "../main/crossblock.h"



namespace vm::logic::cross {

/**
 * @brief The OrBlock class - ||
 */
class OrBlock : public CrossBlock
{
public:
	OrBlock ();

	// LogicBlock interface
	bool calcResult () override;
};

}

#endif // ORBLOCK_H
