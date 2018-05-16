#include "log.h"

#include <context-base/object/object.h>

namespace icL::context::complex {

Log::Log(memory::InterLevel * il)
	: Complex(il) {}

void Log::log(Log::Level level, const QString & message) {
	int levelAsInt = 0;

	if (level == Level::Warm) {
		levelAsInt = 1;
	}
	else if (level == Level::Info) {
		levelAsInt = 2;
	}

	emit newLog(levelAsInt, message);
}

void Log::runAnything(Log::Level level, memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		log(level, args[0].object->getValue().toString());
	}
	else {
		sendWrongArglist(args, "<String>");
	}
}

void Log::runInfo(memory::ArgList & args) {
	runAnything(Level::Info, args);
}

void Log::runWarm(memory::ArgList & args) {
	runAnything(Level::Warm, args);
}

void Log::runError(memory::ArgList & args) {
	runAnything(Level::Error, args);
}

bool Log::checkPrev(const Context * context) const {
	return context == nullptr;
}

bool Log::canBeAtEnd() const {
	return false;
}

Context * Log::runMethod(const QString & name, memory::ArgList & args) {
	if (name == QStringLiteral("info")) {
		runInfo(args);
	}
	else if (name == QStringLiteral("warm")) {
		runWarm(args);
	}
	else if (name == QStringLiteral("error")) {
		runError(args);
	}
	else {
		Context::runMethod(name, args);
	}

	return newContext;
}

}  // namespace icL::context::complex
