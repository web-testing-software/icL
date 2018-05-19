#ifndef COMPLEX_H
#define COMPLEX_H

#include <icl-context/context-base/context.h>


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

class Complex : public Context
{
public:
	Complex(memory::InterLevel * il);

	// Context interface
public:
	bool isComplex() const override;
};

}  // namespace icL::context::complex

#endif  // COMPLEX_H
