#ifndef icL_context_value_SetObject
#define icL_context_value_SetObject


#include "../base/value.h"

#include <icl-memory/state/datastate.h>
#include <icl-memory/structures/set.h>

namespace old::context::value {

class SetObject : public Value
{
public:
	SetObject(memory::InterLevel * il, memory::SetObjPtr data);

	QVariant getField(const QString & name);
	//

private:
	memory::SetObjPtr data;
};

}  // namespace old::context::value

#endif  // icL_context_value_SetObject
