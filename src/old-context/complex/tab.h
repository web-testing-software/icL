#ifndef icL_context_complex_Tab
#define icL_context_complex_Tab

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

class Tab : public Complex
{
public:
	Tab(memory::InterLevel * il);

	bool get(const QString & url);

private:
	void runGet(memory::ArgList & args);

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool canBeAtEnd() const override;

	Context * runMethod(const QString & name, memory::ArgList & args) override;
};

}  // namespace old::context::complex

#endif  // icL_context_complex_Tab
