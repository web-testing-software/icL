#ifndef IF_H
#define IF_H

#include "control.h"



namespace vm::context::code::control {

class If : public Control
{
public:
	If ();

protected:
	bool expressionExecuted = false;
	bool result				= false;

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool isExecuable () const override;
	bool execute () override;

	Context* getBeginContext () override;
	Context* getEndContext () override;
};

} // namespace

#endif // IF_H