#ifndef SLOT_H
#define SLOT_H

#include "catch.h"



namespace vm::context::code::control::catch0 {

class Slot : public Catch
{
public:
	Slot();

	bool giveSignal(int code);

protected:
	int signal;
	int gettedSignal;

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool isExecuable() const override;
	bool execute() override;

	Context* getBeginContext() override;
	Context* getEndContext() override;
};

}  // namespace vm::context::code::control::catch0

#endif  // SLOT_H
