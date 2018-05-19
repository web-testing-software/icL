#ifndef CONTROL_H
#define CONTROL_H

#include "main/code.h"



/**
 *  icL
 *  |- app
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- @namespace control
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

class Control : public Code
{
public:
	Control(memory::InterLevel * il, const memory::CodeFragment & source);

	// Context interface
public:
	bool canBeAtEnd() const override;
	bool isRightToLeft() const override;
};

}  // namespace icL::context::code::control

#endif  // CONTROL_H
