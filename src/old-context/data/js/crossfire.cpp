#include "crossfire.h"


namespace old::context::data::js {

Crossfire::Crossfire(memory::InterLevel * il)
    : File(il) {}

memory::StepType::Value Crossfire::execute() {
	if (!checkArgs()) {
		il->vm->exception(
		  {-203,
		   "Wrong arglist for $crossfire, expected <String, CommandEnd>"});
		return memory::StepType::None;
	}

	QString code = getFileContent();

	if (!code.isEmpty()) {
		code.replace("$:crossfire", il->vms->getCrossfirePass());

		il->server->runJS(code);
	}

	return memory::StepType::MiniStep;
}

}  // namespace old::context::data::js
