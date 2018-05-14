#ifndef DOM_H
#define DOM_H

#include "complex.h"

#include <icl-memory/structures/webelement.h>


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

class Dom : Complex
{
public:
	Dom() = default;

	memory::WebElement query (const QString& selector);
	memory::WebElement queryAll (const QStringList& selectors);

private:
	void runQuery(memory::ArgList& args);
	void runQueryAll(memory::ArgList& args);

private:
	static int     idAsInt;
	static QString getNewId();

signals:
	void requestJsExecution(
	  const QString& str, std::function<void(const QVariant& var)> feedback);

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool canBeAtEnd() const override;

	Context* runMethod(const QString& name, memory::ArgList& args) override;
};

}  // namespace icL::context::complex

#endif  // DOM_H
