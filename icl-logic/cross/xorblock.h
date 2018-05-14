#ifndef XORBLOCK_H
#define XORBLOCK_H

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
 * @brief The XOrBlock class - ^^
 */
class XOrBlock : public CrossBlock
{
public:
	XOrBlock();

	// LogicBlock interface
	bool calcResult() override;
};

}  // namespace vm::logic::cross

#endif  // XORBLOCK_H
