#ifndef ORBLOCK_H
#define ORBLOCK_H

#include "../main/crossblock.h"


/**
 * vm
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
namespace vm::logic::cross {

/**
 * @brief The OrBlock class - ||
 */
class OrBlock : public CrossBlock
{
public:
	OrBlock();

	// LogicBlock interface
	bool calcResult() override;
	bool canResultPreliminarily() override;
};

}  // namespace vm::logic::cross

#endif  // ORBLOCK_H
