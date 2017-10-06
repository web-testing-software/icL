#ifndef ORBLOCK_H
#define ORBLOCK_H

#include "../main/crossblock.h"



namespace vm {
namespace system {
namespace logic {
namespace cross {

class OrBlock : public CrossBlock
{
public:
	OrBlock ();

	// LogicBlock interface
	bool getResult() override;
};

}   // namespace cross
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // ORBLOCK_H
