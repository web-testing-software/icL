#ifndef icL_logic_cross_And
#define icL_logic_cross_And

#include "../main/cross.h"


namespace icL::logic::cross {

/**
 * @deprecated
 * @brief The And class - &&
 */
class And : public Cross
{
public:
	And(memory::InterLevel * il);

	// Logic interface
	bool calcResult() override;
	bool canResultPreliminarily() override;
};

}  // namespace icL::logic::cross

#endif  // icL_logic_cross_And
