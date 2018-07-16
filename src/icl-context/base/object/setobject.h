#ifndef icL_context_object_SetObject
#define icL_context_object_SetObject


#include "object.h"

#include <icl-memory/state/datastate.h>
#include <icl-memory/structures/set.h>

namespace icL::context::object {

class SetObject
	: public object::Value
{
public:
	SetObject(memory::InterLevel * il, memory::SetObjPtr data);

private:
	memory::SetObjPtr data;
};

}  // namespace icL::context::object

#endif  // icL_context_object_SetObject
