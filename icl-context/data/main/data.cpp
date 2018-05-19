#include "data.h"

namespace icL::context::data {

Data::Data(memory::InterLevel * il)
	: Context(il){};



bool Data::canBeAtEnd() const {
	return false;
}

bool Data::isExecuable() const {
	return m_prev->role() == Role::Object;
}

}  // namespace icL::context::data
