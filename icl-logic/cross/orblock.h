#ifndef ORBLOCK_H
#define ORBLOCK_H

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
 * @brief The OrBlock class - ||
 */
class OrBlock : public CrossBlock
{
public:
	OrBlock(memory::InterLevel * il);

	// LogicBlock interface
	bool calcResult() override;
	bool canResultPreliminarily() override;
};

}  // namespace icL::logic::cross

#endif  // ORBLOCK_H
