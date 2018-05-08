#ifndef CODE_H
#define CODE_H

#include <context.h>



namespace vm::context::code {

class Code : public Context
{
public:
	Code ();

	// Context interface
public:
	bool checkPrev(const Context *context) const override;
	bool canBeAtEnd() const override;
	bool isExecuable () const override;
};

} // namespace

#endif // CODE_H
