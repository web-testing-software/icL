#ifndef INTBLOCK_H
#define INTBLOCK_H

#include "../main/richblock.h"



namespace vm {
namespace system {
namespace logic {
namespace rich {

class IntBlock : public RichBlock
{
public:
	IntBlock (OperationType otype);

	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult () override;

private:
	static int varNameToValue (const QString &varname);

	static QRegExp exp;
};

}   // namespace rich
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // INTBLOCK_H
