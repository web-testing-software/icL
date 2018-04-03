#ifndef EQBLOCK_H
#define EQBLOCK_H

#include "../main/crossblock.h"

namespace vm::logic::cross {

/**
 * @brief The EqBlock class - ~~
 */
class EqBlock : public CrossBlock
{
public:
	EqBlock ();

	// LogicBlock interface
protected:
	bool calcResult () override;
};

}

#endif // EQBLOCK_H
