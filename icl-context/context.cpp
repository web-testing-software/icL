#include <utility>

#include "context.h"


namespace vm::context {

Context::Context () = default;

void Context::repeat (QString *str, int begin, int end, std::function <void ( QVariant& )> func) {
	emit interrupt (str, begin, end, std::move(func));
}

} // namespace
