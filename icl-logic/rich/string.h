#ifndef STRINGBLOCK_H
#define STRINGBLOCK_H

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
 * @brief The String class - compare two <string> vars/consts
 */
class String : public Rich
{
public:
	String(memory::InterLevel *il, OperationType otype);
	String(memory::InterLevel *il, Rich * block);

	//	static bool check (const QString &value);

	// Logic interface
	bool calcResult() override;

protected:
	//	QString varNameToString (const QString &varname);

private:
	//	static QRegExp exp;
};

}  // namespace icL::logic::rich

#endif  // STRINGBLOCK_H
