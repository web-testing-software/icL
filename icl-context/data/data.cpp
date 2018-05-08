#include "data.h"

namespace vm::context::data {

Data::Data () = default;



bool Data::isExecuable () {
	return m_prev->role () == Role::Object;
}

}
