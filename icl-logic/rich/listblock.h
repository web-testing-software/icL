#ifndef LISTBLOCK_H
#define LISTBLOCK_H

#include "../main/rich.h"


/**
 *  icL
 *  |- app
 *	|- context
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
 * @brief The StringListBlock class - compare two <string>list vars/consts
 */
class ListBlock : public RichBlock
{
public:
	ListBlock(memory::InterLevel *il, OperationType otype);
	ListBlock(memory::InterLevel *il, RichBlock * block);

	static bool check(const QString & value);

	// LogicBlock interface
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

#endif  // LISTBLOCK_H
