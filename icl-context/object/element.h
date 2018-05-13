#ifndef ELEMENT_H
#define ELEMENT_H

#include "object.h"



namespace vm::context::object {

class Element : public Object
{
public:
	Element(memory::DataState* container, const QString& varName);
	Element(const QVariant& rvalue, bool readonly = false);
	Element(const Object* const object);

	// Context interface
public:
	Context* runProperty(const QString& name) override;
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

#endif  // ELEMENT_H
