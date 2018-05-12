#ifndef INT_H
#define INT_H

#include "object.h"



namespace vm::context::object {

class Int : public Object
{
public:
	Int(memory::DataState* container, const QString& varName);
	Int(const QVariant& rvalue, bool readonly = false);
	Int(const Object* const object);
};

}  // namespace vm::context::object

#endif  // INT_H
