#ifndef icL_logic_cross_XOr
#define icL_logic_cross_XOr

#include "../main/cross.h"


namespace old::logic::cross {

/**
 * @deprecated
 * @brief The XOr class - ^^
 */
class XOr : public Cross
{
public:
	XOr(memory::InterLevel * il);

	// Logic interface
	bool calcResult() override;
};

}  // namespace old::logic::cross

#endif  // icL_logic_cross_XOr
