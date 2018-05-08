#ifndef OBJECT_H
#define OBJECT_H

#include <context.h>



namespace vm::context::object {

class Object : public Context
{
public:
	Object ();

	// Context interface
public:
	bool checkPrev(const Context *context) const override;
};

} // namespace

#endif // OBJECT_H
