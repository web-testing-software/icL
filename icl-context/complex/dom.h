#ifndef DOM_H
#define DOM_H

#include "complex.h"



namespace vm::context::complex {

class Dom : Complex
{
public:
	Dom();

	// Context interface
public:
	bool     checkPrev(const Context* context) const override;
	bool     canBeAtEnd() const override;
	Context* runMethod(const QString& name, memory::ParamList& params) override;
};

}  // namespace vm::context::complex

#endif  // DOM_H
