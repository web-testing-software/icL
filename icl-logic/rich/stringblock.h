#ifndef STRINGBLOCK_H
#define STRINGBLOCK_H

#include "../main/richblock.h"



namespace vm::main::logic::rich {

class StringBlock : public RichBlock
{
public:
	StringBlock (OperationType otype);

	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult () override;

protected:
	QString varNameToString (const QString &varname);

private:
	static QRegExp exp;
};

}

#endif // STRINGBLOCK_H
