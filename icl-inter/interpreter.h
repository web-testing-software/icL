#ifndef icL_inter_Interpreter
#define icL_inter_Interpreter

#include "flayer.h"

#include <icl-context/base/context.h>
#include <icl-memory/interlevel/interfaces.h>
#include <icl-memory/interlevel/node.h>

#include <functional>


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
 *  |-> inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::inter {

class Interpreter
	: public memory::Node
	, public memory::Interpreter
{
public:
	Interpreter(memory::InterLevel * il);

	/**
	 * @brief parseNext - parse next semantic block
	 * @return a bock has parsed
	 */
	context::Context * parseNext();

	void ride(int begin, int end);


	// memory.Interpreter interface
	virtual void newSignal(int code, const QString & name) override;
	virtual Flayer & getFlayer() override;


protected:
	context::Context * parseKeyword();
	context::Context * parseString();
	context::Context * parseStateVar();
	context::Context * parseLocalVar();
	context::Context * parseJavascript();
	context::Context * parseExist();
	context::Context * parseAny();
	context::Context * parseFunction();
	context::Context * parseNumber();
	context::Context * parseProperty();
	context::Context * parseMethod();
	context::Context * parseParameter();
	context::Context * parseAssign();
	context::Context * parseConsole();
	context::Context * parseList();
	context::Context * parseSystemVar();
	context::Context * parseCode();
	context::Context * parseAlternative();

private:
	Flayer flayer;
};

}  // namespace icL::inter

#endif  // icL_inter_Interpreter
