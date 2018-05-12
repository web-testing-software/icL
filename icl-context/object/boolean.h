#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "object.h"



namespace vm::context::object {

class Boolean : public Object
{
public:
	Boolean(memory::DataState* container, const QString& varName);
	Boolean(const QVariant& rvalue, bool readonly = false);
	Boolean(const Object* const object);
};

}  // namespace vm::context::object

#endif  // BOOLEAN_H
