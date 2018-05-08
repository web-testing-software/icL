#ifndef TRY_H
#define TRY_H

#include "catch.h"



namespace vm::context::code::control::catch0 {

class Exists : public Catch
{
public:
	Exists ();

	int signal() const;

private:
	int m_signal = 0;

	// Context interface
public:
	bool isExecuable () const override;
};

} // namespace
#endif // TRY_H
