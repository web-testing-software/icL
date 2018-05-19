#ifndef CATCH_H
#define CATCH_H

#include "../main/control.h"


/**
 *  icL
 *  |- app
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
namespace icL::context::code::control::catch0 {

class Catch : public Control
{
public:
	Catch(memory::InterLevel * il, const memory::CodeFragment & source);
};

}  // namespace icL::context::code::control::catch0

#endif  // CATCH_H
