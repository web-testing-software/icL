#ifndef ORBLOCK_H
#define ORBLOCK_H

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
 * @brief The Or class - ||
 */
class Or : public Cross
{
public:
	Or(memory::InterLevel * il);

	// Logic interface
	bool calcResult() override;
	bool canResultPreliminarily() override;
};

}  // namespace icL::logic::cross

#endif  // ORBLOCK_H
