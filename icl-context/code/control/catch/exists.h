#ifndef EXISTS_H
#define EXISTS_H

#include "catch.h"



namespace vm::context::code::control::catch0 {

class Exists : public Catch
{
public:
	Exists ();

	int signal () const;

private:
	int m_signal = 0;

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool isExecuable () const override;
	bool execute () override;

	Context *getBeginContext() override;
	Context* getEndContext () override;
};

} // namespace
#endif // EXISTS_H
