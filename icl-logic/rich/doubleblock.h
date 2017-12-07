#ifndef DOUBLEBLOCK_H
#define DOUBLEBLOCK_H

#include "../main/richblock.h"



namespace vm::main::logic::rich {

class DoubleBlock : public RichBlock
{
public:
	DoubleBlock (OperationType otype);

	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult () override;

protected:
	double varNameToDouble (const QString &varname);

private:
	static QRegExp exp;
};

}

#endif // DOUBLEBLOCK_H
