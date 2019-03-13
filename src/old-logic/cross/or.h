#ifndef icL_logic_cross_Or
#define icL_logic_cross_Or

#include "../main/cross.h"


namespace old::logic::cross {

/**
 * @deprecated
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

}  // namespace old::logic::cross

#endif  // icL_logic_cross_Or
