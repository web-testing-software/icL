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
namespace old::context::data {

class Assign : public Data
{
public:
	Assign(memory::InterLevel * il);

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool isExecutable() const override;

	memory::StepType::Value execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;
};

}  // namespace old::context::data

#endif  // icL_context_data_Assign
