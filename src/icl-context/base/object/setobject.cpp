#include "setobject.h"

namespace icL::context::value {

SetObject::SetObject(memory::InterLevel * il, memory::SetObjPtr data)
	: object::Value(il, nullptr, QString{})
	, data(data) {}

}  // namespace icL::context::value
