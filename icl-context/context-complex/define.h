#ifndef DEFINE_H
#define DEFINE_H

#include "complex.h"


/**
 * vm
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
namespace vm::context::complex {

class Define : public Complex
{
public:
	Define() = default;

	void signal(int code, const QString& name);

private:
	void runSignal(memory::ArgList& args);

signals:
	void newSignal(int code, const QString& name);

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool canBeAtEnd() const override;

	Context* runMethod(const QString& name, memory::ArgList& args) override;
};

}  // namespace vm::context::complex

#endif  // DEFINE_H
