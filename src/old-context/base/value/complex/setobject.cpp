#include "setobject.h"

namespace old::context::value {

SetObject::SetObject(memory::InterLevel * il, memory::SetObjPtr data)
    : Value(il, nullptr, QString{})
    , data(data) {}

}  // namespace old::context::value
