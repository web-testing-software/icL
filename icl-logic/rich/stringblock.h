#ifndef STRINGBLOCK_H
#define STRINGBLOCK_H

#include "../main/richblock.h"



namespace vm::logic::rich {

/**
 * @brief The StringBlock class - compare two <string> vars/consts
 */
class StringBlock : public RichBlock
{
public:
	StringBlock (OperationType otype);

//	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult () override;

protected:
//	QString varNameToString (const QString &varname);

private:
//	static QRegExp exp;
};

}

#endif // STRINGBLOCK_H
