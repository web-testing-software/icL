#ifndef TAB_H
#define TAB_H

#include "complex.h"


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

class Tab : Complex
{
public:
	Tab() = default;

	bool get(const QString & url);

private:
	void runGet(memory::ArgList & args);

signals:
	void getSignal(const QString & url, std::function<void(bool)> feedbback);

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool canBeAtEnd() const override;

	Context * runMethod(const QString & name, memory::ArgList & args) override;
};

}  // namespace icL::context::complex

#endif  // TAB_H
