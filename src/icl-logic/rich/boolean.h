#ifndef icL_logic_rich_Boolean
#define icL_logic_rich_Boolean

#include "../main/rich.h"


namespace icL::logic::rich {

/**
 * @deprecated
 * @brief The Boolean class - compare two <bool> vars/consts
 */
class Boolean : public Rich
{
public:
	Boolean(memory::InterLevel *il, OperationType otype);
	Boolean(memory::InterLevel *il, Rich * block);

	//	static bool check (const QString &value);

	// Logic interface
	bool calcResult() override;

protected:
	//	bool varNameToBoolean (const QString &varname);
};

}  // namespace icL::logic::rich

#endif  // icL_logic_rich_Boolean
