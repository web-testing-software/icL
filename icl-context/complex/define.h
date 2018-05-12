#ifndef DEFINE_H
#define DEFINE_H

#include "complex.h"



namespace vm::context::complex {

class Define : public Complex
{
public:
	Define ();

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool canBeAtEnd () const override;
	bool isRightToLeft () const override;
	bool isExecuable () const override;
	bool execute () override;
	Context* getBeginContext () override;
	Context* getEndContext () override;
	Context* runMethod (const QString &name, memory::ParamList &params) override;
};

} // namespace

#endif // DEFINE_H
