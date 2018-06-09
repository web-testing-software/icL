#include "setobject.h"

namespace icL::context::object {

SetObject::SetObject() {}

void SetObject::setValue(const QString & name, const QVariant & value) {}

bool SetObject::contains(const QString & name) {}

memory::Type SetObject::getType(const QString & name) {}

bool SetObject::checkType(const QString & name, memory::Type & type) {}

QVariant SetObject::getValue(const QString & name) {}

}  // namespace icL::context::object
