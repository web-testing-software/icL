#ifndef ELEMENT_H
#define ELEMENT_H

#include "object.h"



namespace vm::context::object {

class Element : public Object
{
public:
	Element (memory::DataState *container, const QString &varName);
	Element (const QVariant &rvalue, bool readonly = false);
	Element (const Object *const object);
};

} // namespace

#endif // ELEMENT_H
