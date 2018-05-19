#ifndef DOUBLEBLOCK_H
#define DOUBLEBLOCK_H

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
 * @brief The Double class - compare two <double> vars/consts
 */
class Double : public Rich
{
public:
	Double(memory::InterLevel *il, OperationType otype);
	Double(memory::InterLevel *il, Rich * block);

	//	static bool check (const QString &value);

	// Logic interface
	bool calcResult() override;

protected:
	//	double varNameToDouble (const QString &varname);

private:
	//	static QRegExp exp;
};

}  // namespace icL::logic::rich

#endif  // DOUBLEBLOCK_H
