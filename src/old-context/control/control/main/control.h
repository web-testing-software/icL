#ifndef icL_context_code_control_Control
#define icL_context_code_control_Control

#include "../../main/code.h"



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
namespace old::context::code::control {

class Control : public Code
{
public:
	Control(memory::InterLevel * il, const memory::CodeFragment & source);

	// Context interface
public:
	bool canBeAtEnd() const override;
	bool isRightToLeft() const override;
};

}  // namespace old::context::code::control

#endif  // icL_context_code_control_Control
