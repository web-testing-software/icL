#ifndef DOUBLEBLOCK_H
#define DOUBLEBLOCK_H

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
 * @brief The DoubleBlock class - compare two <double> vars/consts
 */
class DoubleBlock : public RichBlock
{
public:
	DoubleBlock(OperationType otype);
	DoubleBlock(RichBlock* block);

	//	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult() override;

protected:
	//	double varNameToDouble (const QString &varname);

private:
	//	static QRegExp exp;
};

}  // namespace vm::logic::rich

#endif  // DOUBLEBLOCK_H
