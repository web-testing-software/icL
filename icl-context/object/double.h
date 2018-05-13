#ifndef DOUBLE_H
#define DOUBLE_H

#include "object.h"



namespace vm::context::object {

class Double : public Object
{
public:
	Double(memory::DataState* container, const QString& varName);
	Double(const QVariant& rvalue, bool readonly = false);
	Double(const Object* const object);

	// Context interface
public:
	Context* runMethod(const QString& name, memory::ArgList& args) override;

	// Object interface
public:
	bool               toBoolean() override;
	int                toInt() override;
	double             toDouble() override;
	const QString&     toString() override;
	const QStringList& toList() override;
};

}  // namespace vm::context::object

#endif  // DOUBLE_H
