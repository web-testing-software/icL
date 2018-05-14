#ifndef EQBLOCK_H
#define EQBLOCK_H

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

}  // namespace icL::logic::cross

#endif  // EQBLOCK_H
