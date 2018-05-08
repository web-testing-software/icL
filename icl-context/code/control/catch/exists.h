#ifndef TRY_H
#define TRY_H

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
	bool execute () const override;

	Context* getNewContext () const override;
	Context* getBeginContext () const override;
	Context* getEndContext () const override;
};

} // namespace
#endif // TRY_H
