#ifndef icL_context_code_control_Slot
#define icL_context_code_control_Slot

#include "catch.h"


/**
 *  icL
 *  |- app
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- @namespace catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::context::code::control::catch0 {

class Slot : public Catch
{
public:
	Slot(memory::InterLevel * il);

	bool giveSignal(int code);

protected:
	int signal;
	int gettedSignal;

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool isExecuable() const override;
	bool execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;
};

}  // namespace icL::context::code::control::catch0

#endif  // icL_context_code_control_Slot
