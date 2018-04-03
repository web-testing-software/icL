#include "context.h"


namespace vm::context {

Context::Context () {
}

void Context::repeat (QString *str, int begin, int end, std::function <void ( QVariant& )> func) {
	emit interrupt (str, begin, end, func);
}

} // namespace
