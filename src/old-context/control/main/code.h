#ifndef icL_context_code_Code
#define icL_context_code_Code


#include <icl-context/base/context.h>
#include <icl-memory/structures/functioncontainer.h>


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
namespace old::context::code {

class Code : public Context
{
public:
	Code(memory::InterLevel * il, const memory::CodeFragment & source);

	const memory::CodeFragment & source() const;

protected:
	bool executed = false;

	memory::CodeFragment m_source;

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool isRightToLeft() const override;
	bool canBeAtEnd() const override;
	bool isExecutable() const override;

	memory::StepType::Value execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;
};

}  // namespace old::context::code

#endif  // icL_context_code_Code
