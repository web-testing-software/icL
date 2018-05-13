#ifndef FUNCTION_H
#define FUNCTION_H


#include <context-base/context.h>

#include <icl-memory/state/memory.h>



namespace vm::context::function {

class Function : public Context
{
public:
	Function(memory::Memory* mem, const QString& name);

protected:
	bool exNewFunction();
	bool exCallFunction();

	bool checkParamsNum(memory::Function& func);
	bool checkParamsTypes(memory::Function& func);
	void sendWrongArgs();

private:
	memory::Memory* mem;

	QString name;
	bool    newFunction      = false;
	bool    functionExecuted = false;

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool canBeAtEnd() const override;
	bool isExecuable() const override;
	bool execute() override;

	Context* getBeginContext() override;
	Context* getEndContext() override;

	bool isResultative() const override;
};

}  // namespace vm::context::function

#endif  // FUNCTION_H
