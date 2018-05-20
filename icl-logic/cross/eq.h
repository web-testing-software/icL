#ifndef icL_logic_cross_Eq
#define icL_logic_cross_Eq

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
 *  |  |- @namespace cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::logic::cross {

/**
 * @brief The Eq class - ~~
 */
class Eq : public Cross
{
public:
	Eq(memory::InterLevel * il);

	// Logic interface
protected:
	bool calcResult() override;
};

}  // namespace icL::logic::cross

#endif  // icL_logic_cross_Eq
