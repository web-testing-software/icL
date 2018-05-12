#ifndef TAB_H
#define TAB_H

#include "complex.h"



namespace vm::context::complex {

class Tab : Complex
{
public:
	Tab ();

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool canBeAtEnd () const override;
	Context* runMethod (const QString &name, memory::ParamList &params) override;
};

} // namespace

#endif // TAB_H
