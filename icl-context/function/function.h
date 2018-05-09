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
	bool checkPrev (const Context *context) const override;
	bool canBeAtEnd () const override;
	bool isExecuable () const override;
	bool execute () const override;

	const Context* getBeginContext () const override;
	const Context* getEndContext () const override;
};

} // namespace

#endif // FUNCTION_H
