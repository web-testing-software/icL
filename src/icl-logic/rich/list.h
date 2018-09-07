#ifndef icL_logic_rich_List
#define icL_logic_rich_List

#include "../main/rich.h"


namespace icL::logic::rich {

/**
 * @deprecated
 * @brief The StringListBlock class - compare two <string>List vars/consts
 */
class ListBlock : public Rich
{
public:
	ListBlock(memory::InterLevel *il, OperationType otype);
	ListBlock(memory::InterLevel *il, Rich * block);

	static bool check(const QString & value);

	// Logic interface
	bool calcResult() override;

protected:
	//	QStringList varNameToStringList (const QString &varname);

private:
	static bool operatorEqual(
	  const QStringList & list1, const QStringList & list2);
	static bool containsFragment(
	  const QStringList & strList, const QString & str);

	//	static QRegExp exp;
	//	static QRegularExpression strExp;
};

}  // namespace icL::logic::rich

#endif  // icL_logic_rich_List
