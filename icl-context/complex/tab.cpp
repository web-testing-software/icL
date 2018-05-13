#include "tab.h"

#include <object/object.h>

namespace vm::context::complex {

bool Tab::get(const QString& url) {
	emit getSignal(url, [this](bool success){
		this->newValue = success;
	});

	return newValue.toBool();
}

void Tab::runGet(memory::ArgList& args) {
	if (args.length() == 1 && args[0].object->type() != memory::Type::String) {
		get(args[0].object->getValue().toString());
		newContext = fromValue(newValue);
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

bool Tab::checkPrev(const Context* context) const {
	return context == nullptr;
}

bool Tab::canBeAtEnd() const {
	return false;
}

Context* Tab::runMethod(const QString& name, memory::ArgList& args) {
	if (name == QStringLiteral("get")) {
		runGet(args);
	}
	else {
		Context::runMethod(name, args);
	}

	return newContext;
}

}  // namespace vm::context::complex
