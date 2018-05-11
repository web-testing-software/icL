#include "void.h"

namespace vm::context::object {

Void::Void ()
	: Object (QVariant (), true) {

};

} // namespace
