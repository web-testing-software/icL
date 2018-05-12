#ifndef DOUBLE_H
#define DOUBLE_H

#include "object.h"



namespace vm::context::object {

class Double : public Object
{
public:
	Double(memory::DataState* container, const QString& varName);
	Double(const QVariant& rvalue, bool readonly = false);
	Double(const Object* const object);
};

}  // namespace vm::context::object

#endif  // DOUBLE_H
