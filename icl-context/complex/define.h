#ifndef DEFINE_H
#define DEFINE_H

#include "complex.h"



namespace vm::context::complex {

class Define : public Complex
{
public:
	Define();

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool canBeAtEnd() const override;

	Context* runMethod(const QString& name, memory::ParamList& params) override;
};

}  // namespace vm::context::complex

#endif  // DEFINE_H
