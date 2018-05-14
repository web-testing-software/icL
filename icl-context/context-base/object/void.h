#ifndef VOID_H
#define VOID_H

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

}  // namespace icL::context::object

#endif  // VOID_H
