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
	bool execute () const override;

	Context* getNewContext () const override;
	Context* getBeginContext () const override;
	Context* getEndContext () const override;
};

} // namespace

#endif // IF_H
