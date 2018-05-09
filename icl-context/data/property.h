#ifndef PROPERTY_H
#define PROPERTY_H

#include "data.h"



namespace vm::context::data {

class Property : public Data
{
public:
	Property ();

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool canBeAtEnd () const override;
	bool execute () const override;

	const Context* getBeginContext () const override;
	const Context* getEndContext () const override;
};

} // namespace

#endif // PROPERTY_H
