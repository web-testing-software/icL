#ifndef icL_context_data_js_Value
#define icL_context_data_js_Value

#include "js.h"



namespace old::context::data::js {

class Value : public Js
{
public:
	Value(memory::InterLevel * il);

	QString getCode();

	// Context interface
public:
	bool      checkPrev(const Context * context) const override;
	Context * getBeginContext() override;
	Context * getEndContext() override;
	bool      isResultative() const override;
};

}  // namespace old::context::data::js

#endif  // icL_context_data_js_Value
