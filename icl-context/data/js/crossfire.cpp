#include "crossfire.h"


namespace icL::context::data::js {

Crossfire::Crossfire(memory::InterLevel * il, const QString &fileName)
	: File(il, fileName) {}

bool Crossfire::execute()
{
	if (!checkArgs()) {
		il->vm->exception(
		  {-203, "Wrong arglist for $file, expected <String, CommandEnd>"});
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
