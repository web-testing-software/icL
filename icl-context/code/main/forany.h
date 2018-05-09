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
	bool checkPrev (const Context *context) const override;
	bool isExecuable () const override;
	bool execute () const override;

	const Context* getBeginContext () const override;
	const Context* getEndContext () const override;
};

} // namespace

#endif // ISOLATED_H
