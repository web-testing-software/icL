#ifndef icL_context_data_js_Set
#define icL_context_data_js_Set

#include "value.h"



namespace old::context::data::js {

class Set : public Value
{
public:
	Set(memory::InterLevel * il);

	// Context interface
public:
	memory::StepType::Value execute() override;
};

}  // namespace old::context::data::js

#endif  // icL_context_data_js_Set
