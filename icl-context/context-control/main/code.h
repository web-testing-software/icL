#ifndef CODE_H
#define CODE_H


#include <context-base/context.h>

#include <icl-memory/structures/functioncontainer.h>


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

class Code : public Context
{
public:
	Code(const memory::CodeFragment& source);

	const memory::CodeFragment& source() const;

protected:
	bool                 executed;
	memory::CodeFragment m_source;

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool canBeAtEnd() const override;
	bool isExecuable() const override;
	bool execute() override;

	Context* getBeginContext() override;
	Context* getEndContext() override;
};

}  // namespace vm::context::code

#endif  // CODE_H
