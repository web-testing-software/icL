#include "define.h"

#include <object/object.h>

namespace vm::context::complex {

Define::Define() {}

bool Define::checkPrev(const Context* context) const {
	return context == nullptr;
}

bool Define::canBeAtEnd() const {
	return false;
}

Context* Define::runMethod(const QString& name, memory::ArgList& args) {
	const QString expectedArgs = "<Int, String>";

	if (args.length() != 2) {
		sendWrongArglist(args, expectedArgs);
	}
	else if (name == "signal") {
		memory::Argument &a1 = args[0], &a2 = args[1];

		if (
		  a1.object->type() != memory::Type::Int ||
		  a2.object->type() != memory::Type::String) {
			sendWrongArglist(args, expectedArgs);
		}
		else {
			emit newSignal(
			  a1.object->getValue().toInt(), a2.object->getValue().toString());
		}
	}
}

}  // namespace vm::context::complex
