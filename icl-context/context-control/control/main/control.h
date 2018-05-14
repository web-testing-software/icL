#ifndef CONTROL_H
#define CONTROL_H

#include <main/code.h>



/**
 * vm
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
namespace vm::context::code::control {

class Control : public Code
{
public:
	Control(const memory::CodeFragment& source);

	// Context interface
public:
	bool canBeAtEnd() const override;
	bool isRightToLeft() const override;
};

}  // namespace vm::context::code::control

#endif  // CONTROL_H
