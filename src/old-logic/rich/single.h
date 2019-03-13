#ifndef icL_logic_rich_Single
#define icL_logic_rich_Single

#include "../main/rich.h"

namespace old::logic::rich {


/**
 * @deprecated
 * @brief The Single class - compare a <bool> var/const with a predefined
 * const
 */
class Single : public Rich
{
public:
	Single(memory::InterLevel * il, OperationType otype);

protected:
	bool calcResult() override;

	// Logic interface
public:
	bool checkIntegrity() override;
	bool needCast() override;
	bool canResultPreliminarily() override;
};

}  // namespace old::logic::rich

#endif  // icL_logic_rich_Single
