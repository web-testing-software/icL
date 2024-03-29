#ifndef icL_context_code_control_catch_Exists
#define icL_context_code_control_catch_Exists

#include "catch.h"


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '-> catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace old::context::code::control::catch0 {

class Exists : public Catch
{
public:
	Exists(
	  memory::InterLevel * il, const memory::CodeFragment & source,
	  bool isEmiter);

	bool getIsEmiter() const;

private:
	bool isEmiter = false;

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool isExecutable() const override;

	memory::StepType::Value execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;

	bool isResultative() const override;
};

}  // namespace old::context::code::control::catch0

#endif  // icL_context_code_control_catch_Exists
