#ifndef icL_logic_rich_Int
#define icL_logic_rich_Int

#include "../main/rich.h"


namespace old::logic::rich {

/**
 * @deprecated
 * @brief The Int class - compare two <int> vars/consts
 */
class Int : public Rich
{
public:
	Int(memory::InterLevel * il, OperationType otype);
	Int(memory::InterLevel * il, Rich * block);

	//	static bool check (const QString &value);

	// Logic interface
	bool calcResult() override;

protected:
	//	int varNameToInt (const QString &varname);

private:
	//	static QRegExp exp;
};

}  // namespace old::logic::rich

#endif  // icL_logic_rich_Int
