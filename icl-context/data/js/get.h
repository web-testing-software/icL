#ifndef icL_context_data_js_Get
#define icL_context_data_js_Get

#include "value.h"



namespace icL::context::data::js {

class Get : public Value
{
public:
	Get(memory::InterLevel * il);

	// Context interface
public:
	memory::StepType execute() override;
};

}  // namespace icL::context::data::js

#endif  // icL_context_data_js_Get
