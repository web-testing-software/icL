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
	bool isRightToLeft() const override;
	bool isExecuable() const override;
};

} // namespace

#endif // ALTERNATIVE_H
