#ifndef ASSIGN_H
#define ASSIGN_H

#include "data.h"



namespace vm::context::data {

class Assign : public Data
{
public:
	Assign ();

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool isExecuable () const override;
	bool execute () const override;

	const Context* getBeginContext () const override;
	const Context* getEndContext () const override;
};

} // namespace

#endif // ASSIGN_H
