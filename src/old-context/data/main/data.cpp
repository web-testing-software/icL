#include "data.h"

namespace old::context::data {

Data::Data(memory::InterLevel * il)
    : Context(il){};



bool Data::canBeAtEnd() const {
	return false;
}

bool Data::isExecutable() const {
	return m_prev->role() == Role::Object;
}

}  // namespace old::context::data
