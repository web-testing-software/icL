#include "setobject.h"

namespace icL::context::object {

SetObject::SetObject(memory::InterLevel * il, memory::SetObjPtr data)
	: object::Object(il, nullptr, QString{})
	, data(data) {}

}  // namespace icL::context::object
