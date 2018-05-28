#ifndef icL_context_complex_Dom
#define icL_context_complex_Dom

#include "complex.h"

#include <icl-memory/structures/webelement.h>


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
namespace icL::context::complex {

class Dom : public Complex
{
public:
	Dom(memory::InterLevel * il);

	memory::WebElement query(const QString & selector);
	memory::WebElement queryAll(const QStringList & selectors);

private:
	void runQuery(memory::ArgList & args);
	void runQueryAll(memory::ArgList & args);

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool canBeAtEnd() const override;

	Context * runMethod(const QString & name, memory::ArgList & args) override;
};

}  // namespace icL::context::complex

#endif  // icL_context_complex_Dom
