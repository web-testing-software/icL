#ifndef METHOD_H
#define METHOD_H

#include "data.h"



namespace vm::context::data {

class Method : public Data
{
public:
	Method ();

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool canBeAtEnd () const override;
	bool execute () const override;

	Context* getBeginContext () const override;
	Context* getEndContext () const override;
};

} // namespace

#endif // METHOD_H
