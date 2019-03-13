#ifndef icL_context_complex_Log
#define icL_context_complex_Log

#include "complex.h"


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |-> complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace old::context::complex {

class Log : public Complex
{
	enum class Level { Info, Warm, Error };

public:
	Log(memory::InterLevel * il);

	void log(Level level, const QString & message);

private:
	void runAnything(Level level, memory::ArgList & args);

	void runInfo(memory::ArgList & args);
	void runWarm(memory::ArgList & args);
	void runError(memory::ArgList & args);

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool canBeAtEnd() const override;

	Context * runMethod(const QString & name, memory::ArgList & args) override;
};

}  // namespace old::context::complex

#endif  // icL_context_complex_Log
