#ifndef SET_H
#define SET_H

#include "value.h"



namespace icL::context::data::js {

class Set : public Value
{
public:
	Set(memory::InterLevel * il);

	// Context interface
public:
	bool execute() override;
};

}  // namespace icL::context::data::js

#endif  // SET_H
