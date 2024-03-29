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
namespace old::context::data {

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
	bool isExecutable() const override;

	memory::StepType::Value execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;
};

}  // namespace old::context::data

#endif  // icL_context_data_Alternative
