#ifndef SLOT_H
#define SLOT_H

#include "catch.h"


/**
 *  icL
 *  |- app
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- @namespace catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::context::code::control::catch0 {

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
	bool checkPrev(const Context * context) const override;
	bool isExecuable() const override;
	bool execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;
};

}  // namespace icL::context::code::control::catch0

#endif  // SLOT_H
