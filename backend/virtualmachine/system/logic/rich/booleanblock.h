#ifndef BOOLEANBLOCK_H
#define BOOLEANBLOCK_H

#include "../main/richblock.h"



namespace vm {
namespace main {
namespace logic {
namespace rich {

class BooleanBlock : public RichBlock
{
public:
	BooleanBlock (OperationType otype);

	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult () override;

protected:
	bool varNameToBoolean (const QString &varname);
};

}   // namespace rich
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // BOOLEANBLOCK_H
