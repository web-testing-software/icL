#ifndef XORBLOCK_H
#define XORBLOCK_H

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
 * @brief The XOrBlock class - ^^
 */
class XOrBlock : public CrossBlock
{
public:
	XOrBlock();

	// LogicBlock interface
	bool calcResult() override;
};

}  // namespace icL::logic::cross

#endif  // XORBLOCK_H
