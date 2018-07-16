#ifndef icL_context_value_SetObject
#define icL_context_value_SetObject


#include "value.h"

#include <icl-memory/state/datastate.h>
#include <icl-memory/structures/set.h>

namespace icL::context::value {

class SetObject
	: public object::Value
{
public:
	SetObject(memory::InterLevel * il, memory::SetObjPtr data);

private:
	memory::SetObjPtr data;
};

}  // namespace icL::context::value

#endif  // icL_context_value_SetObject
