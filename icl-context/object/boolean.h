#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "object.h"



namespace vm::context::object {

class Boolean : public Object
{
public:
	Boolean(memory::DataState* container, const QString& varName);
	Boolean(const QVariant& rvalue, bool readonly = false);
	Boolean(const Object* const object);

	// Context interface
public:
	Context* runMethod(const QString& name, memory::ArgList& args) override;

	// Object interface
public:
	bool              toBoolean() override;
	int               toInt() override;
	double            toDouble() override;
	const QString     toString() override;
	const QStringList toList() override;
};

}  // namespace vm::context::object

#endif  // BOOLEAN_H
