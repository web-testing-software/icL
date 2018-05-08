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
	bool isExecuable () override;
};

} // namespace

#endif // CODE_H
