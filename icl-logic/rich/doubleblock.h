#ifndef DOUBLEBLOCK_H
#define DOUBLEBLOCK_H

#include "../main/richblock.h"


/**
 *  icL
 *  |- app
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
namespace icL::logic::rich {

/**
 * @brief The DoubleBlock class - compare two <double> vars/consts
 */
class DoubleBlock : public RichBlock
{
public:
	DoubleBlock(memory::InterLevel *il, OperationType otype);
	DoubleBlock(memory::InterLevel *il, RichBlock * block);

	//	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult() override;

protected:
	//	double varNameToDouble (const QString &varname);

private:
	//	static QRegExp exp;
};

}  // namespace icL::logic::rich

#endif  // DOUBLEBLOCK_H
