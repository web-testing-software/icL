#ifndef STRING_H
#define STRING_H

#include "object.h"


namespace vm::context::object {

class String : public Object
{
public:
	String(memory::DataState* container, const QString& varName);
	String(const QVariant& rvalue, bool readonly = false);
	String(const Object* const object);

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

#endif  // STRING_H
