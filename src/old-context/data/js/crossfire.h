#ifndef icL_context_data_js_Crossfire
#define icL_context_data_js_Crossfire

#include "file.h"


namespace old::context::data::js {

class Crossfire : public File
{
public:
	Crossfire(memory::InterLevel * il);

	// Context interface
public:
	memory::StepType::Value execute() override;
};

}  // namespace old::context::data::js

#endif  // icL_context_data_js_Crossfire
