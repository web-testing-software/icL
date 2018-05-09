#ifndef OBJECT_H
#define OBJECT_H

#include <context.h>



namespace vm::context::object {

class Object : public Context
{
public:
	Object ();

	memory::Type type();

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool canBeAtEnd () const override;
};

} // namespace

#endif // OBJECT_H
