#ifndef ANDBLOCK_H
#define ANDBLOCK_H

#include "../main/crossblock.h"


/**
 *  icL
 *  |- app
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- @namespace cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::logic::cross {

/**
 * @brief The AndBlock class - &&
 */
class AndBlock : public CrossBlock
{
public:
	AndBlock(memory::InterLevel * il);

	// LogicBlock interface
	bool calcResult() override;
	bool canResultPreliminarily() override;
};

}  // namespace icL::logic::cross

#endif  // ANDBLOCK_H
