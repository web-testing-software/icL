#ifndef icL_context_data_js_Var
#define icL_context_data_js_Var

#include "value.h"



namespace icL::context::data::js {

class Var : public Value
{
public:
	Var(memory::InterLevel * il);

protected:
	std::pair<QString, QString> getArguments();

	// Context interface
public:
	memory::StepType::Value execute() override;
};

}  // namespace icL::context::data::js

#endif  // icL_context_data_js_Var
