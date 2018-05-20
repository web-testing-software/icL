#ifndef icL_logic_rich_Int
#define icL_logic_rich_Int

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
 *  |  '- @namespace rich
 *  '- memory
 */
namespace icL::logic::rich {

/**
 * @brief The Int class - compare two <int> vars/consts
 */
class Int : public Rich
{
public:
	Int(memory::InterLevel *il, OperationType otype);
	Int(memory::InterLevel *il, Rich * block);

	//	static bool check (const QString &value);

	// Logic interface
	bool calcResult() override;

protected:
	//	int varNameToInt (const QString &varname);

private:
	//	static QRegExp exp;
};

}  // namespace icL::logic::rich

#endif  // icL_logic_rich_Int
