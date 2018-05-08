#ifndef FUNCTION_H
#define FUNCTION_H

#include <context.h>



namespace vm::context::function {

class Function : public Context
{
public:
	Function ();

private:
	bool newFunction = false;

	// Context interface
public:
	bool checkPrev(const Context *context) const override;
	bool isExecuable () const override;
};

} // namespace

#endif // FUNCTION_H
