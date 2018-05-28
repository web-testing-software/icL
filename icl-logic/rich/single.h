#ifndef icL_logic_rich_Single
#define icL_logic_rich_Single

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
 * @brief The Single class - compare a <bool> var/const with a predefined
 * const
 */
class Single : public Rich
{
public:
	Single(memory::InterLevel *il, OperationType otype);

protected:
	bool calcResult() override;

	// Logic interface
public:
	bool checkIntegrity() override;
	bool needCast() override;
	bool canResultPreliminarily() override;
};

}  // namespace icL::logic::rich

#endif  // icL_logic_rich_Single
