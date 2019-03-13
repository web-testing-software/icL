#ifndef icL_context_complex_Define
#define icL_context_complex_Define

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

class Define : public Complex
{
public:
	Define(memory::InterLevel * il);

	void signal(int code, const QString & name);

private:
	void runSignal(memory::ArgList & args);

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool canBeAtEnd() const override;

	Context * runMethod(const QString & name, memory::ArgList & args) override;
};

}  // namespace old::context::complex

#endif  // icL_context_complex_Define
