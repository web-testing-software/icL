#include "interpreter.h"

#include <utility>

namespace icL::inter {

Interpreter::Interpreter(QObject* parent)
	: QObject(parent) {}

void Interpreter::repeat(
  memory::FunctionCall run, std::function<void(memory::Return&)> feedback) {
	emit interrupt(std::move(run), std::move(feedback));
}

}  // namespace icL::inter
