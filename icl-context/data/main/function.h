#ifndef icL_context_data_Function
#define icL_context_data_Function


#include <icl-memory/state/memory.h>

#include <icl-context/base/context.h>


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |-> data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::context::data {

class Function : public Context
{
public:
	Function(memory::InterLevel * il, const QString & name);

protected:
	memory::StepType::Value exNewFunction();
	memory::StepType::Value exCallFunction();

	bool checkParamsNum(memory::Function & func);
	bool checkParamsTypes(memory::Function & func);
	void sendWrongArgs();

private:
	QString name;
	bool    newFunction      = false;
	bool    functionExecuted = false;

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool canBeAtEnd() const override;
	bool isExecuable() const override;

	memory::StepType::Value execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;

	bool isResultative() const override;
};

}  // namespace icL::context::data

#endif  // icL_context_data_Function
