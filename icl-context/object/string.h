#ifndef STRING_H
#define STRING_H

#include "object.h"


namespace vm::context::object {

class String : public Object
{
public:
	String(memory::DataState* container, const QString& varName);
	String(const QVariant& rvalue, bool readonly = false);
	String(const Object* const object);
};

}  // namespace vm::context::object

#endif  // STRING_H
