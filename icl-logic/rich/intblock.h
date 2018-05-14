#ifndef INTBLOCK_H
#define INTBLOCK_H

#include "../main/richblock.h"


/**
 * vm
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- @namespace rich
 *  '- memory
 */
namespace vm::logic::rich {

/**
 * @brief The IntBlock class - compare two <int> vars/consts
 */
class IntBlock : public RichBlock
{
public:
	IntBlock(OperationType otype);
	IntBlock(RichBlock* block);

	//	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult() override;

protected:
	//	int varNameToInt (const QString &varname);

private:
	//	static QRegExp exp;
};

}  // namespace vm::logic::rich

#endif  // INTBLOCK_H
