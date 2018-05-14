#ifndef COMPLEX_H
#define COMPLEX_H

#include <context-base/context.h>


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

class Complex : public Context
{
public:
	Complex() = default;

	// Context interface
public:
	bool isComplex() const override;
};

}  // namespace vm::context::complex

#endif  // COMPLEX_H
