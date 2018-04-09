#ifndef ISOLATED_H
#define ISOLATED_H

#include "code.h"



namespace vm::context::code {

class Isolated : public Code
{
public:
	Isolated ();
};

} // namespace

#endif // ISOLATED_H
