#ifndef NOTBLOCK_H
#define NOTBLOCK_H

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
 * @brief The NotBlock class - !
 */
class NotBlock : public CrossBlock
{
public:
	NotBlock();

	// LogicBlock interface
	bool calcResult() override;
	bool checkIntegrity() override;
	void resetResultValue() override;
};

}  // namespace icL::logic::cross

#endif  // NOTBLOCK_H
