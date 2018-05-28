#ifndef icL_logic_cross_Or
#define icL_logic_cross_Or

#include "../main/cross.h"


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |-> cross
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

#endif  // icL_logic_cross_Or
