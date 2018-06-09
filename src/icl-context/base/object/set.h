#ifndef icl_context_object_Set
#define icl_context_object_Set

#include "object.h"

#include <icl-memory/structures/set.h>

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
	Set(
	  memory::InterLevel * il, memory::DataState * container,
	  const QString & varName);
	Set(
	  memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);

	// static data
private:
	static const QHash<QString, void (Set::*)()>                  properties;
	static const QHash<QString, void (Set::*)(memory::ArgList &)> methods;

public:
	static const QHash<QString, void (Set::*)()> initProperties();
	static const QHash<QString, void (Set::*)(memory::ArgList &)> initMethods();

	// Properties
public:
	int  length();
	bool empty();

private:
	void runLength();
	void runEmpty();

	void prepend(const memory::Row & row);
	void append(const memory::Row & row);
	void appplicate(const QList<QStringList> & list);
	void insert(const memory::Row & row);
	void merge(const memory::Table & table);

	void popFront();
	void popBack();
	void removeAt(int index);
	void remove(const memory::Row & row);

	memory::Row get(int index);
	int         ref(const memory::Row & value);

private:
	void runPrepend(memory::ArgList & args);
	void runAppend(memory::ArgList & args);
	void runApplicate(memory::ArgList & args);
	void runInsert(memory::ArgList & args);
	void runMerge(memory::ArgList & args);

	void runPopFront(memory::ArgList & args);
	void runPopBack(memory::ArgList & args);
	void runRemoveAt(memory::ArgList & args);
	void runRemove(memory::ArgList & args);

	void runGet(memory::ArgList & args);
	void runRef(memory::ArgList & args);

	// Back-end
private:
	// Context interface
public:
	Context * runProperty(Prefix prefix, const QString & name) override;
	Context * runMethod(const QString & name, memory::ArgList & args) override;

	// Object interface
public:
	memory::Type type() const override;

	bool   toBoolean() override;
	int    toInt() override;
	double toDouble() override;

	const QString     toString() override;
	const QStringList toList() override;
};


}  // namespace icL::context::object


#endif  // icl_context_object_Set
