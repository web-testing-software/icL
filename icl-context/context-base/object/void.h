#ifndef VOID_H
#define VOID_H

#include "object.h"



namespace vm::context::object {

class Void : public Object
{
public:
	Void();

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

#endif  // VOID_H
