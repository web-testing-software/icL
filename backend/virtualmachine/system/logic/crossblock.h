#ifndef CROSSBLOCK_H
#define CROSSBLOCK_H

#include "logicblock.h"



namespace vm {
namespace system {
namespace logic {

class CrossBlock : public LogicBlock
{
public:
	CrossBlock ();

private:
	LogicBlock *block1;
	LogicBlock *block2;
};

}
}
}

#endif // CROSSBLOCK_H
