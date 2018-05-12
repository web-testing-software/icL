#ifndef VOID_H
#define VOID_H

#include "object.h"



namespace vm::context::object {

class Void : public Object
{
public:
	Void();
};

}  // namespace vm::context::object

#endif  // VOID_H
