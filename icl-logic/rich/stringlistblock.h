#ifndef STRINGLISTBLOCK_H
#define STRINGLISTBLOCK_H

#include "../main/richblock.h"

#include "stringblock.h"



namespace vm::logic::rich {

/**
 * @brief The StringListBlock class - compare two <string>list vars/consts
 */
class ListBlock : public StringBlock
{
public:
	ListBlock (OperationType otype);

	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult () override;

protected:
//	QStringList varNameToStringList (const QString &varname);

private:
	static bool operatorEqual (const QStringList &list1, const QStringList &list2);
	static bool containsFragment (const QStringList &strList, const QString &str);

//	static QRegExp exp;
//	static QRegularExpression strExp;
};

}

#endif // STRINGLISTBLOCK_H
