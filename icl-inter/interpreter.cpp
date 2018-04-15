#include "interpreter.h"

#include <utility>

namespace vm::inter {

Interpreter::Interpreter (QObject *parent) : QObject (parent) {

}

void Interpreter::repeat (QString *str, int begin, int end, std::function <void ( QVariant& )> func) {
	emit interrupt (str, begin, end, std::move(func));
}

} // namespace
