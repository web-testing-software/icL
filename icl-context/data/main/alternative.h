#ifndef icL_context_data_Alternative
#define icL_context_data_Alternative

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

class Alternative : public Data
{
public:
	Alternative(memory::InterLevel * il);

private:
	bool theLeftOperandIsOk = false;

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool isRightToLeft() const override;
	bool isExecuable() const override;

	memory::StepType execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;
};

}  // namespace icL::context::data

#endif  // icL_context_data_Alternative
