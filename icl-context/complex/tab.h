#ifndef TAB_H
#define TAB_H

#include "complex.h"



namespace vm::context::complex {

class Tab : Complex
{
public:
	Tab();

	// Context interface
public:
	bool     checkPrev(const Context* context) const override;
	bool     canBeAtEnd() const override;
	Context* runMethod(const QString& name, memory::ArgList& args) override;
};

}  // namespace vm::context::complex

#endif  // TAB_H
