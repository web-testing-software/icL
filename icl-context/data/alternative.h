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
	bool isRightToLeft() override;
	bool isExecuable() override;
};

} // namespace

#endif // ALTERNATIVE_H
