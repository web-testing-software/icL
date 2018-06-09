#ifndef icl_context_object_List
#define icl_context_object_List

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

class Set : public Object
{
public:
	Set(memory::InterLevel * il, memory::DataState * container, const QString & varName);
	Set(memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);

	// static data
private:
	static const QHash<QString, void (Set::*)()>                  properties;
	static const QHash<QString, void (Set::*)(memory::ArgList &)> methods;

public:
	static const QHash<QString, void (Set::*)()> initProperties();
	static const QHash<QString, void (Set::*)(memory::ArgList &)>
	initMethods();

	// Properties
public:
	int length();
	bool empty();

private:
	void runLength();
	void runEmpty();

	// Methods
public:
	// Temporary empty

private:
	// Temporary empty

	// Back-end
private:

	// Context interface
public:
	Context * runProperty(Prefix prefix, const QString & name) override;
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

#endif  // icl_context_object_List
