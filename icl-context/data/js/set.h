#ifndef icL_context_data_js_Set
#define icL_context_data_js_Set

#include "value.h"



namespace icL::context::data::js {

class Set : public Value
{
public:
	Set(memory::InterLevel * il);

	// Context interface
public:
	memory::StepType execute() override;
};

}  // namespace icL::context::data::js

#endif  // icL_context_data_js_Set
