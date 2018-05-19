#ifndef NOTBLOCK_H
#define NOTBLOCK_H

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
 * @brief The Not class - !
 */
class Not : public Cross
{
public:
	Not(memory::InterLevel * il);

	// Logic interface
	bool calcResult() override;
	bool checkIntegrity() override;
	void resetResultValue() override;
};

}  // namespace icL::logic::cross

#endif  // NOTBLOCK_H
