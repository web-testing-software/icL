#ifndef DEFINE_H
#define DEFINE_H

#include "complex.h"



namespace vm::context::complex {

class Define : public Complex
{
public:
	Define();

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
