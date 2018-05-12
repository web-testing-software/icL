#ifndef FORANY_H
#define FORANY_H

#include "code.h"



namespace vm::context::code {

class ForAny : public Code
{
public:
	ForAny (const memory::CodeFragment &source);

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool isExecuable () const override;
	bool execute () override;

	Context* getBeginContext () override;
	Context* getEndContext () override;

	bool isResultative() const override;
};

} // namespace

#endif // FORANY_H
