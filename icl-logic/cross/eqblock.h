#ifndef EQBLOCK_H
#define EQBLOCK_H

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
 * @brief The EqBlock class - ~~
 */
class EqBlock : public CrossBlock
{
public:
	EqBlock();

	// LogicBlock interface
protected:
	bool calcResult() override;
};

}  // namespace vm::logic::cross

#endif  // EQBLOCK_H
