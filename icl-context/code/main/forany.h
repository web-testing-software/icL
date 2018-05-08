#ifndef ISOLATED_H
#define ISOLATED_H

#include "code.h"



namespace vm::context::code {

class ForAny : public Code
{
public:
	ForAny ();

	// Context interface
public:
	bool isExecuable () const override;
};

} // namespace

#endif // ISOLATED_H
