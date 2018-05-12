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
	AndBlock();

	// LogicBlock interface
	bool calcResult() override;
	bool canResultPreliminarily() override;
};

}  // namespace vm::logic::cross

#endif  // ANDBLOCK_H
