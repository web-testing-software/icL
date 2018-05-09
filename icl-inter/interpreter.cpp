#include "interpreter.h"

#include <utility>

namespace vm::inter {

Interpreter::Interpreter (QObject *parent) : QObject (parent) {

}

void Interpreter::repeat (memory::Function run, std::function <void ( memory::Return& )> feedback) {
	emit interrupt (run, feedback);
}

} // namespace
