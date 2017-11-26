#ifndef ANDBLOCK_H
#define ANDBLOCK_H

#include "../main/crossblock.h"



namespace vm {
namespace main {
namespace logic {
namespace cross {

class AndBlock : public CrossBlock
{
public:
	AndBlock ();

	// LogicBlock interface
	bool calcResult () override;
};

}   // namespace cross
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // ANDBLOCK_H
