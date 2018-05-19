#ifndef DOUBLE_H
#define DOUBLE_H

#include "object.h"


/**
 *  icL
 *  |- app
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- @namespace object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::context::object {

class Double : public Object
{
public:
	Double(memory::InterLevel * il, memory::DataState * container, const QString & varName);
	Double(memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);
	Double(memory::InterLevel * il, const QString & getter, const QString & setter);
	Double(memory::InterLevel * il, const Object * const object);

	// Context interface
public:
	Context * runMethod(const QString & name, memory::ArgList & args) override;

	// Object interface
public:
	memory::Type type() const override;

	bool              toBoolean() override;
	int               toInt() override;
	double            toDouble() override;
	const QString     toString() override;
	const QStringList toList() override;
};

}  // namespace icL::context::object

#endif  // DOUBLE_H
