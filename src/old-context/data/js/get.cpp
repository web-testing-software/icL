#include "get.h"

#include <icl-context/base/object/void.h>

namespace old::context::data::js {

Get::Get(memory::InterLevel * il)
    : Value(il) {}

memory::StepType::Value Get::execute() {
	QString code = getCode();

	if (code.isEmpty()) {
		il->vm->exception(
		  {-203,
		   "Wrong call of $get, the javascript code is missing or empty"});
		return memory::StepType::None;
	}

	QVariant ret = il->server->runJS(code);

	if (ret.isNull()) {
		newContext = new object::Void{il};
	}
	else {
		newContext = fromValue(ret);
	}

	return memory::StepType::MiniStep;
}

}  // namespace old::context::data::js
