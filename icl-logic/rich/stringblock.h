#ifndef STRINGBLOCK_H
#define STRINGBLOCK_H

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
 * @brief The StringBlock class - compare two <string> vars/consts
 */
class StringBlock : public RichBlock
{
public:
	StringBlock(OperationType otype);
	StringBlock(RichBlock * block);

	//	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult() override;

protected:
	//	QString varNameToString (const QString &varname);

private:
	//	static QRegExp exp;
};

}  // namespace icL::logic::rich

#endif  // STRINGBLOCK_H
