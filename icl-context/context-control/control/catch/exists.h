#ifndef EXISTS_H
#define EXISTS_H

#include "catch.h"



namespace vm::context::code::control::catch0 {

class Exists : public Catch
{
public:
	Exists(const memory::CodeFragment& source, bool isEmiter);

	bool getIsEmiter() const;

private:
	bool isEmiter = false;

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool isExecuable() const override;
	bool execute() override;

	Context* getBeginContext() override;
	Context* getEndContext() override;
};

}  // namespace vm::context::code::control::catch0
#endif  // EXISTS_H
