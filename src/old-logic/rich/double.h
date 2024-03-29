#ifndef icL_logic_rich_Double
#define icL_logic_rich_Double

#include "../main/rich.h"


namespace old::logic::rich {

/**
 * @deprecated
 * @brief The Double class - compare two <double> vars/consts
 */
class Double : public Rich
{
public:
	Double(memory::InterLevel * il, OperationType otype);
	Double(memory::InterLevel * il, Rich * block);

	//	static bool check (const QString &value);

	// Logic interface
	bool calcResult() override;

protected:
	//	double varNameToDouble (const QString &varname);

private:
	//	static QRegExp exp;
};

}  // namespace old::logic::rich

#endif  // icL_logic_rich_Double
