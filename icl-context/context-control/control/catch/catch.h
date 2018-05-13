#ifndef CATCH_H
#define CATCH_H

#include <control/main/control.h>



namespace vm::context::code::control::catch0 {

class Catch : public Control
{
public:
	Catch(const memory::CodeFragment& source);
};

}  // namespace vm::context::code::control::catch0

#endif  // CATCH_H
