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
	bool isExecuable () const override;
};

} // namespace

#endif // ASSIGN_H
