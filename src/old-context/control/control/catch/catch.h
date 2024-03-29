#ifndef icL_context_code_control_catch_Catch
#define icL_context_code_control_catch_Catch

#include "../main/control.h"


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '-> catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace old::context::code::control::catch0 {

class Catch : public Control
{
public:
	Catch(memory::InterLevel * il, const memory::CodeFragment & source);
};

}  // namespace old::context::code::control::catch0

#endif  // icL_context_code_control_catch_Catch
