#ifndef ELSE_H
#define ELSE_H

#include "control.h"


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

class Else : public Control
{
public:
	Else();

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool isExecuable() const override;
	bool execute() override;

	Context* getBeginContext() override;
	Context* getEndContext() override;
};

}  // namespace vm::context::code::control

#endif  // ELSE_H
