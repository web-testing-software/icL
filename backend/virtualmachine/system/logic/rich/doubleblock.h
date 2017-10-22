#ifndef DOUBLEBLOCK_H
#define DOUBLEBLOCK_H

#include "../main/richblock.h"



namespace vm {
namespace system {
namespace logic {
namespace rich {

class DoubleBlock : public RichBlock
{
public:
	DoubleBlock (OperationType otype);

	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult () override;

private:
	static double varNameToValue (LogicBlock *block, const QString &varname);

	static QRegExp exp;
};

}   // namespace rich
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // DOUBLEBLOCK_H
