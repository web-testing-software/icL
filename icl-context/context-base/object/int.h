#ifndef INT_H
#define INT_H

#include "object.h"


/**
 * vm
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
namespace vm::context::object {

class Int : public Object
{
public:
	Int(memory::DataState* container, const QString& varName);
	Int(const QVariant& rvalue, bool readonly = false);
	Int(const QString& getter, const QString& setter);
	Int(const Object* const object);

	// Context interface
public:
	Context* runMethod(const QString& name, memory::ArgList& args) override;

	// Object interface
public:
	memory::Type type() const override;

	bool              toBoolean() override;
	int               toInt() override;
	double            toDouble() override;
	const QString     toString() override;
	const QStringList toList() override;
};

}  // namespace vm::context::object

#endif  // INT_H
