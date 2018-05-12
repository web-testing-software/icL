#ifndef ASSIGN_H
#define ASSIGN_H

#include "data.h"



namespace vm::context::data {

class Assign : public Data
{
public:
	Assign();

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool isExecuable() const override;
	bool execute() override;

	Context* getBeginContext() override;
	Context* getEndContext() override;
};

}  // namespace vm::context::data

#endif  // ASSIGN_H
