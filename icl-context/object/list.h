#ifndef LIST_H
#define LIST_H

#include "object.h"



namespace vm::context::object {

class List : public Object
{
public:
	List (memory::DataState *container, const QString &varName);
	List (const QVariant &rvalue, bool readonly = false);
	List (const Object *const object);
};

} // namespace

#endif // LIST_H
