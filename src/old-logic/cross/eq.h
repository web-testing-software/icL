#ifndef icL_logic_cross_Eq
#define icL_logic_cross_Eq

#include "../main/cross.h"


namespace old::logic::cross {

/**
 * @deprecated
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

}  // namespace old::logic::cross

#endif  // icL_logic_cross_Eq
