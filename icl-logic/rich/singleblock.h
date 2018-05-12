#ifndef SINGLEBLOCK_H
#define SINGLEBLOCK_H

#include "../main/richblock.h"


namespace vm::logic::rich {


/**
 * @brief The SingleBlock class - compare a <bool> var/const with a predefined
 * const
 */
class SingleBlock : public RichBlock
{
public:
	SingleBlock(OperationType otype);

protected:
	bool calcResult() override;

	// LogicBlock interface
public:
	bool checkIntegrity() override;
	bool needCast() override;
	bool canResultPreliminarily() override;
};

}  // namespace vm::logic::rich
#endif  // SINGLEBLOCK_H
