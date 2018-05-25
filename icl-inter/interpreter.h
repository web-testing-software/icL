#ifndef icL_inter_Interpreter
#define icL_inter_Interpreter

#include <icl-context/base/context.h>
#include <icl-context/base/object/int.h>
#include <icl-memory/structures/functioncontainer.h>
#include <icl-memory/structures/return.h>

#include <functional>

#include <QObject>


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- @namespace inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::inter {

class Interpreter
{
public:
	Interpreter();

	/**
	 * @brief parseNext - parse next semantic block
	 * @return a bock has parsed
	 */
	bool parseNext();
};

}  // namespace icL::inter

#endif  // icL_inter_Interpreter
