#ifndef icl_context_object_Int
#define icl_context_object_Int

#include "object.h"


/**
 *  icL
 *  |- app
 *  |- context
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

class Int : public Object
{
public:
	Int(memory::InterLevel * il, memory::DataState * container, const QString & varName);
	Int(memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);
	Int(memory::InterLevel * il, const QString & getter, const QString & setter);
	Int(memory::InterLevel * il, const Object * const object);

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

#endif  // icl_context_object_Int
