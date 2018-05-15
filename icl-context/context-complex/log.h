#ifndef LOG_H
#define LOG_H

#include "complex.h"


/**
 *  icL
 *  |- app
 *	|- context
 *  |  |- @namespace complex
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
namespace icL::context::complex {

class Log : Complex
{
	enum class Level { Info, Warm, Error };

public:
	Log() = default;

	void log(Level level, const QString & message);

private:
	void runAnything(Level level, memory::ArgList & args);

	void runInfo(memory::ArgList & args);
	void runWarm(memory::ArgList & args);
	void runError(memory::ArgList & args);

signals:
	void newLog(int level, const QString & message);

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool canBeAtEnd() const override;

	Context * runMethod(const QString & name, memory::ArgList & args) override;
};

}  // namespace icL::context::complex

#endif  // LOG_H
