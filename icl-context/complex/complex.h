#ifndef COMPLEX_H
#define COMPLEX_H

#include <context.h>



namespace vm::context::complex {

class Complex : public Context
{
public:
	Complex();

	// Context interface
public:
	bool isComplex() const override;
};

}  // namespace vm::context::complex

#endif  // COMPLEX_H
