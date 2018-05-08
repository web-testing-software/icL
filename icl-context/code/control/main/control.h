#ifndef CONTROL_H
#define CONTROL_H

#include <code/main/code.h>



namespace vm::context::code::control {

class Control : public Code
{
public:
	Control ();

	// Context interface
public:
	bool isRightToLeft () override;
};

} // namespace

#endif // CONTROL_H
