#ifndef CATCH_H
#define CATCH_H

#include <code/control/main/control.h>



namespace vm::context::code::control::catch0 {

class Catch : public Control
{
public:
	Catch(const memory::CodeFragment &source);
};

} // namespace

#endif // CATCH_H
