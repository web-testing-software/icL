#ifndef icl_context_object_Boolean
#define icl_context_object_Boolean

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
 *  |  '-> object
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
	Boolean(memory::InterLevel * il, memory::DataState * container, const QString & varName);
	Boolean(memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);
	Boolean(memory::InterLevel * il, const QString & getter, const QString & setter);
	Boolean(memory::InterLevel * il, const Object * const object);

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

#endif  // icl_context_object_Boolean
