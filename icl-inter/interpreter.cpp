#include "interpreter.h"

namespace vm::inter {

Interpreter::Interpreter (QObject *parent) : QObject (parent) {

}

void Interpreter::repeat (QString *str, int begin, int end, std::function <void ( QVariant& )> func) {
	emit interrupt (str, begin, end, func);
}

void Interpreter::repeat (QString *str, int begin, int end, std::function <void ( context::Context * )> func) {
	emit interrupt (str, begin, end, func);
}

} // namespace
