#ifndef ALTERNATIVE_H
#define ALTERNATIVE_H

#include "data.h"



namespace vm::context::data {

class Alternative : public Data
{
public:
	Alternative();

private:
	bool theLeftOperandIsOk = false;

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool isRightToLeft() const override;
	bool isExecuable() const override;
	bool execute() override;

	Context* getBeginContext() override;
	Context* getEndContext() override;
};

}  // namespace vm::context::data

#endif  // ALTERNATIVE_H
