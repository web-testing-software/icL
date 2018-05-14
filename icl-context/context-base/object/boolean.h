#ifndef BOOLEAN_H
#define BOOLEAN_H

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

class Boolean : public Object
{
public:
	Boolean(memory::DataState* container, const QString& varName);
	Boolean(const QVariant& rvalue, bool readonly = false);
	Boolean(const QString& getter, const QString& setter);
	Boolean(const Object* const object);

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
	const QStringList toList() override;\
};

}  // namespace icL::context::object

#endif  // BOOLEAN_H
