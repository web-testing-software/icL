#ifndef XORBLOCK_H
#define XORBLOCK_H

#include "../main/cross.h"


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
 * @brief The XOr class - ^^
 */
class XOr : public Cross
{
public:
	XOr(memory::InterLevel * il);

	// Logic interface
	bool calcResult() override;
};

}  // namespace icL::logic::cross

#endif  // XORBLOCK_H
