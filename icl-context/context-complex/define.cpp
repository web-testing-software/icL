#include "define.h"

#include <object/object.h>

namespace vm::context::complex {

void Define::signal(int code, const QString& name) {
	emit newSignal(code, name);
}

void Define::runSignal(memory::ArgList& args) {
	memory::Argument &a1 = args[0], &a2 = args[1];

	if (
	  args.length() != 2 || a1.object->type() != memory::Type::Int ||
	  a2.object->type() != memory::Type::String) {
		sendWrongArglist(args, QStringLiteral("<Int, String>"));
	}
	else {
		signal(a1.object->getValue().toInt(), a2.object->getValue().toString());
	}
}

bool Define::checkPrev(const Context* context) const {
	return context == nullptr;
}

bool Define::canBeAtEnd() const {
	return false;
}

Context* Define::runMethod(const QString& name, memory::ArgList& args) {

	if (name == QStringLiteral("signal")) {
		runSignal(args);
	}
	else {
		Context::runMethod(name, args);
	}

	return newContext;
}

}  // namespace vm::context::complex
