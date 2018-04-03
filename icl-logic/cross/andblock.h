#ifndef ANDBLOCK_H
#define ANDBLOCK_H

#include "../main/crossblock.h"



namespace vm::logic::cross {

/**
 * @brief The AndBlock class - &&
 */
class AndBlock : public CrossBlock
{
public:
	AndBlock ();

	// LogicBlock interface
	bool calcResult () override;
};

}

#endif // ANDBLOCK_H
