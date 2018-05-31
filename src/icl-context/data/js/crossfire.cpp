#include "crossfire.h"


namespace icL::context::data::js {

Crossfire::Crossfire(memory::InterLevel * il)
	: File(il) {}

memory::StepType::Value Crossfire::execute()
{
	if (!checkArgs()) {
		il->vm->exception(
		  {-203, "Wrong arglist for $crossfire, expected <String, CommandEnd>"});
		return memory::StepType::NONE;
	}

	QString code = getFileContent();

	if (!code.isEmpty()) {
		code.replace("$:crossfire", il->vms->getCrossfirePass());

		il->server->runJS(code);
	}

	return memory::StepType::MINI_STEP;
}

}  // namespace icL::context::data::js
