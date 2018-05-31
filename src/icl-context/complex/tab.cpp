#include "tab.h"

#include <icl-context/base/object/boolean.h>
#include <icl-context/base/object/object.h>

namespace icL::context::complex {

Tab::Tab(memory::InterLevel * il)
	: Complex(il) {}

bool Tab::get(const QString & url) {
	newValue = il->server->get(url);

	return newValue.toBool();
}

void Tab::runGet(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		get(args[0].object->getValue().toString());
		newContext = new object::Boolean{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

bool Tab::checkPrev(const Context * context) const {
	return context == nullptr;
}

bool Tab::canBeAtEnd() const {
	return false;
}

Context * Tab::runMethod(const QString & name, memory::ArgList & args) {
	if (name == QStringLiteral("Get")) {
		runGet(args);
	}
	else {
		Context::runMethod(name, args);
	}

	return newContext;
}

}  // namespace icL::context::complex
