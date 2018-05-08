#ifndef ALTERNATIVE_H
#define ALTERNATIVE_H

#include "data.h"



namespace vm::context::data {

class Alternative : public Data
{
public:
	Alternative ();

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool isRightToLeft () const override;
	bool isExecuable () const override;
	bool execute () const override;

	Context* getBeginContext () const override;
	Context* getEndContext () const override;
};

} // namespace

#endif // ALTERNATIVE_H
