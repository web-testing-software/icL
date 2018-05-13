#ifndef LIST_H
#define LIST_H

#include "object.h"



namespace vm::context::object {

class List : public Object
{
public:
	List(memory::DataState* container, const QString& varName);
	List(const QVariant& rvalue, bool readonly = false);
	List(const Object* const object);

	// Context interface
public:
	Context* runProperty(const QString& name) override;
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

#endif  // LIST_H
