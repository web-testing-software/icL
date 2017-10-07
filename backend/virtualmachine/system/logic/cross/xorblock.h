#ifndef XORBLOCK_H
#define XORBLOCK_H

#include "../main/crossblock.h"



namespace vm {
namespace system {
namespace logic {
namespace cross {

class XOrBlock : public CrossBlock
{
public:
	XOrBlock ();

	// LogicBlock interface
	bool getResult () override;
};

}   // namespace cross
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // XORBLOCK_H
