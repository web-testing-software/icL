#include "get.h"

#include <icl-context/base/object/void.h>

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

	QVariant ret = il->server->runJS(code);

	if (ret.isNull()) {
		newContext = new object::Void{il};
	}
	else {
		newContext = fromValue(ret);
	}

	return true;
}

}  // namespace icL::context::data::js
