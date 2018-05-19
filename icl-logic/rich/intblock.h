#ifndef INTBLOCK_H
#define INTBLOCK_H

#include "../main/rich.h"


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
 * @brief The IntBlock class - compare two <int> vars/consts
 */
class IntBlock : public RichBlock
{
public:
	IntBlock(memory::InterLevel *il, OperationType otype);
	IntBlock(memory::InterLevel *il, RichBlock * block);

	//	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult() override;

protected:
	//	int varNameToInt (const QString &varname);

private:
	//	static QRegExp exp;
};

}  // namespace icL::logic::rich

#endif  // INTBLOCK_H
