#ifndef FORANY_H
#define FORANY_H

#include "code.h"


/**
 * vm
 *	|- context
 *  |  |- complex
 *  |  |- @namespace code
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
namespace vm::context::code {

class ForAny : public Code
{
public:
	ForAny(const memory::CodeFragment& source);

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool isExecuable() const override;
	bool execute() override;

	Context* getBeginContext() override;
	Context* getEndContext() override;

	bool isResultative() const override;
};

}  // namespace vm::context::code

#endif  // FORANY_H
