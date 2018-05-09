#ifndef HANDLER_H
#define HANDLER_H

#include "catch.h"



namespace vm::context::code::control::catch0 {

class Slot : public Catch
{
public:
	Slot ();

protected:
	int signal;

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool isExecuable () const override;
	bool execute () const override;

	Context* getBeginContext () override;
	Context* getEndContext () override;
};

} // namespace

#endif // HANDLER_H
