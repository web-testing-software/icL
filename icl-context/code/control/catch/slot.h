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
	bool isExecuable () const override;
};

} // namespace

#endif // HANDLER_H
