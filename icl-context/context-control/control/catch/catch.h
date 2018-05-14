#ifndef CATCH_H
#define CATCH_H

#include <control/main/control.h>


/**
 * vm
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- @namespace catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace vm::context::code::control::catch0 {

class Catch : public Control
{
public:
	Catch(const memory::CodeFragment& source);
};

}  // namespace vm::context::code::control::catch0

#endif  // CATCH_H
