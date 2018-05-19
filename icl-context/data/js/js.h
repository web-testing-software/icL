#ifndef JS_H
#define JS_H

#include <icl-context/base/context.h>



namespace icL::context::data::js {

class Js : public Context
{
public:
	Js(memory::InterLevel * il);

	// Context interface
public:
	bool canBeAtEnd() const override;
	bool isExecuable() const override;
};

}  // namespace icL::context::data::js

#endif  // JS_H
