#ifndef NOTBLOCK_H
#define NOTBLOCK_H

#include "../main/crossblock.h"



namespace vm {
namespace system {
namespace logic {
namespace cross {

class NotBlock : public CrossBlock
{
public:
	NotBlock ();

	// LogicBlock interface
	bool getResult () override;
	bool checkIntegrity () override;
};

}   // namespace cross
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // NOTBLOCK_H
