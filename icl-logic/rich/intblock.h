#ifndef INTBLOCK_H
#define INTBLOCK_H

#include "../main/richblock.h"



namespace vm::main::logic::rich {

class IntBlock : public RichBlock
{
public:
	IntBlock (OperationType otype);

	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult () override;

protected:
	int varNameToInt (const QString &varname);

private:
	static QRegExp exp;
};

}

#endif // INTBLOCK_H
