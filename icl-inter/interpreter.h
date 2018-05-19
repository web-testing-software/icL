#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <icl-context/base/context.h>
#include <icl-context/base/object/int.h>
#include <icl-memory/structures/functioncontainer.h>
#include <icl-memory/structures/return.h>

#include <functional>

#include <QObject>


/**
 *  icL
 *  |- app
 *	|- context
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
	explicit Interpreter();
};

}  // namespace icL::inter

#endif  // INTERPRETER_H
