#ifndef icL_logic_cross_XOr
#define icL_logic_cross_XOr

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

#endif  // icL_logic_cross_XOr
