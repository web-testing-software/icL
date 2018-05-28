#ifndef icL_logic_rich_Double
#define icL_logic_rich_Double

#include "../main/rich.h"


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '-> rich
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

#endif  // icL_logic_rich_Double
