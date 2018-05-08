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
	bool isExecuable () override;
};

} // namespace

#endif // IF_H
