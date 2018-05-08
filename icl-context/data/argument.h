#ifndef ARGUMENT_H
#define ARGUMENT_H

#include "data.h"



namespace vm::context::data {

class Argument : public Data
{
public:
	Argument ();

	// Context interface
public:
	bool checkPrev(const Context *context) const override;
};

} // namespace

#endif // ARGUMENT_H
