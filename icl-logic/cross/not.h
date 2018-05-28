#ifndef icL_logic_cross_Not
#define icL_logic_cross_Not

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

#endif  // icL_logic_cross_Not
