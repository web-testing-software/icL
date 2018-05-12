#ifndef LOG_H
#define LOG_H

#include "complex.h"



namespace vm::context::complex {

class Log : Complex
{
public:
	Log ();

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool canBeAtEnd () const override;

	Context* runMethod (const QString &name, memory::ParamList &params) override;
};

} // namespace

#endif // LOG_H
