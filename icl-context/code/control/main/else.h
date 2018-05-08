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
	bool checkPrev (const Context *context) const override;
	bool isExecuable () const override;
	bool execute () const override;

	Context* getNewContext () const override;
	Context* getBeginContext () const override;
	Context* getEndContext () const override;
};

} // namespace

#endif // ELSE_H
