#ifndef icL_context_data_Assign
#define icL_context_data_Assign

#include "data.h"


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

class Assign : public Data
{
public:
	Assign(memory::InterLevel * il);

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool isExecuable() const override;

	memory::StepType::Value execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;
};

}  // namespace icL::context::data

#endif  // icL_context_data_Assign
