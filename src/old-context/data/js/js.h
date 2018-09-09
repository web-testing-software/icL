#ifndef icL_context_data_js_Js
#define icL_context_data_js_Js

#include <icl-context/base/context.h>



namespace icL::context::data::js {

class Js : public Context
{
public:
	Js(memory::InterLevel * il);

	// Context interface
public:
	bool canBeAtEnd() const override;
	bool isExecutable() const override;
};

}  // namespace icL::context::data::js

#endif  // icL_context_data_js_Js
