#ifndef NOTBLOCK_H
#define NOTBLOCK_H

#include "../main/crossblock.h"



namespace vm::logic::cross {

/**
 * @brief The NotBlock class - !
 */
class NotBlock : public CrossBlock
{
public:
	NotBlock();

	// LogicBlock interface
	bool calcResult() override;
	bool checkIntegrity() override;
	void resetResultValue() override;
};

}  // namespace vm::logic::cross

#endif  // NOTBLOCK_H
