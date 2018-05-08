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
	bool execute () const override;

	Context* getNewContext () const override;
	Context* getBeginContext () const override;
	Context* getEndContext () const override;
};

} // namespace

#endif // PROPERTY_H
