#ifndef icL_context_code_ForAny
#define icL_context_code_ForAny

#include "code.h"


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |-> code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::context::code {

class ForAny : public Code
{
public:
	ForAny(memory::InterLevel * il, const memory::CodeFragment & source);

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool isRightToLeft() const override;
	bool isExecutable() const override;

	memory::StepType::Value execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;

	bool isResultative() const override;
};

}  // namespace icL::context::code

#endif  // icL_context_code_ForAny
