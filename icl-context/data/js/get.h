#ifndef GET_H
#define GET_H

#include "value.h"



namespace icL::context::data::js {

class Get : public Value
{
public:
	Get(memory::InterLevel * il);

	// Context interface
public:
	bool execute() override;
};

}  // namespace icL::context::data::js

#endif  // GET_H
