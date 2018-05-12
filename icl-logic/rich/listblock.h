#ifndef LISTBLOCK_H
#define LISTBLOCK_H

#include "../main/richblock.h"



namespace vm::logic::rich {

/**
 * @brief The StringListBlock class - compare two <string>list vars/consts
 */
class ListBlock : public RichBlock
{
public:
	ListBlock(OperationType otype);
	ListBlock(RichBlock* block);

	static bool check(const QString& value);

	// LogicBlock interface
	bool calcResult() override;

protected:
	//	QStringList varNameToStringList (const QString &varname);

private:
	static bool operatorEqual(
	  const QStringList& list1, const QStringList& list2);
	static bool containsFragment(
	  const QStringList& strList, const QString& str);

	//	static QRegExp exp;
	//	static QRegularExpression strExp;
};

}  // namespace vm::logic::rich

#endif  // LISTBLOCK_H
