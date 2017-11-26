#ifndef NOTBLOCK_H
#define NOTBLOCK_H

#include "../main/crossblock.h"



namespace vm {
namespace main {
namespace logic {
namespace cross {

class NotBlock : public CrossBlock
{
public:
	NotBlock ();

	// LogicBlock interface
	bool calcResult () override;
	bool checkIntegrity () override;
	void resetResultValue () override;
};

}   // namespace cross
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // NOTBLOCK_H
