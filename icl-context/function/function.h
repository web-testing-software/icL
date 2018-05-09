#ifndef FUNCTION_H
#define FUNCTION_H

#include <context.h>

#include <icl-memory/state/memory.h>



namespace vm::context::function {

class Function : public Context
{
public:
	Function ();

protected:
	bool exNewFunction ();
	bool exCallFunction ();

	bool checkParamsNum (memory::Function &func);
	bool checkParamsTypes (memory::Function &func);
	void sendWrongArgs ();

private:
	memory::Memory *mem;
	QString name;
	bool newFunction = false;

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool canBeAtEnd () const override;
	bool isExecuable () const override;
	bool execute () override;

	Context* getBeginContext () override;
	Context* getEndContext () override;
};

} // namespace

#endif // FUNCTION_H
