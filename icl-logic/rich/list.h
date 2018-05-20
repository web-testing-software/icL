#ifndef icL_logic_rich_List
#define icL_logic_rich_List

#include "../main/rich.h"


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- @namespace rich
 *  '- memory
 */
namespace icL::logic::rich {

/**
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
