#ifndef icL_logic_rich_String
#define icL_logic_rich_String

#include "../main/rich.h"


namespace icL::logic::rich {

/**
 * @deprecated
 * @brief The String class - compare two <string> vars/consts
 */
class String : public Rich
{
public:
	String(memory::InterLevel *il, OperationType otype);
	String(memory::InterLevel *il, Rich * block);

	//	static bool check (const QString &value);

	// Logic interface
	bool calcResult() override;

protected:
	//	QString varNameToString (const QString &varname);

private:
	//	static QRegExp exp;
};

}  // namespace icL::logic::rich

#endif  // icL_logic_rich_String
