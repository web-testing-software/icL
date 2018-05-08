#ifndef METHOD_H
#define METHOD_H

#include "data.h"



namespace vm::context::data {

class Method : public Data
{
public:
	Method ();

	// Context interface
public:
	bool checkPrev(const Context *context) const override;
};

} // namespace

#endif // METHOD_H
