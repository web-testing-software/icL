#ifndef VOID_H
#define VOID_H

#include "object.h"



namespace vm::context::object {

class Void : public Object
{
public:
	Void ();
};

} // namespace

#endif // VOID_H
