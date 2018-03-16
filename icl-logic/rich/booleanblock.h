#ifndef BOOLEANBLOCK_H
#define BOOLEANBLOCK_H

#include "../main/richblock.h"



namespace vm::main::logic::rich {

/**
 * @brief The BooleanBlock class - compare two <bool> vars/consts
 */
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

}

#endif // BOOLEANBLOCK_H
