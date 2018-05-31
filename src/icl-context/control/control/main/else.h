#ifndef icL_context_code_control_Else
#define icL_context_code_control_Else

#include "control.h"


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '-> control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::context::code::control {

class Else : public Control
{
public:
	Else(memory::InterLevel * il);

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool isExecutable() const override;

	memory::StepType::Value execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;
};

}  // namespace icL::context::code::control

#endif  // icL_context_code_control_Else
