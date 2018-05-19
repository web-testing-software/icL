#include "get.h"

namespace icL::context::data::js {

Get::Get(memory::InterLevel * il)
	: Value(il) {}

bool Get::execute() {
	QString code = getCode();

	if (code.isEmpty()) {
		il->vm->exception(
		  {-203,
		   "Wrong call of $get, the javascript code is missing or empty"});
		return false;
	}

	il->server->runJS(code);
}

}  // namespace icL::context::data::js
