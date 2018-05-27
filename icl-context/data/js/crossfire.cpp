#include "crossfire.h"


namespace icL::context::data::js {

Crossfire::Crossfire(memory::InterLevel * il)
	: File(il) {}

bool Crossfire::execute()
{
	if (!checkArgs()) {
		il->vm->exception(
		  {-203, "Wrong arglist for $crossfire, expected <String, CommandEnd>"});
		return false;
	}

	QString code = getFileContent();

	if (!code.isEmpty()) {
		code.replace("$:crossfire", il->vms->getCrossfirePass());

		il->server->runJS(code);
	}
	else {
		return true;
	}

	return true;
}

}  // namespace icL::context::data::js
