#ifndef FUNCTION_H
#define FUNCTION_H

#include <context.h>



namespace vm::context::function {

class Function : public Context
{
public:
	Function ();

	// Context interface
public:
	bool isExecuable () override;
};

} // namespace

#endif // FUNCTION_H
