#ifndef STRINGLISTBLOCK_H
#define STRINGLISTBLOCK_H

#include "../main/richblock.h"

#include "stringblock.h"



namespace vm::main::logic::rich {

/**
 * @brief The StringListBlock class - compare two <string>list vars/consts
 */
class StringListBlock : public StringBlock
{
public:
	StringListBlock (OperationType otype);

	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult () override;

protected:
	QStringList varNameToStringList (const QString &varname);

private:
	static bool operatorEqual (const QStringList &list1, const QStringList &list2);

	static QRegExp exp;
	static QRegularExpression strExp;
};

}

#endif // STRINGLISTBLOCK_H
