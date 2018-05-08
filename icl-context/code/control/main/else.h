#ifndef ELSE_H
#define ELSE_H

#include "control.h"



namespace vm::context::code::control {

class Else : public Control
{
public:
	Else ();

	// Context interface
public:
	bool isExecuable() const override;
};

} // namespace

#endif // ELSE_H
