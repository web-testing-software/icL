#ifndef icl_context_object_Set
#define icl_context_object_Set

#include "object.h"

#include <bits/shared_ptr.h>


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

using Row   = QLinkedList<QVariant>;
using Table = QLinkedList<Row>;

struct SetPtr
{
	std::shared_ptr<memory::ParamList *> header;
	std::shared_ptr<Table *>             table;
};

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

	void prepend(const Row & row);
	void append(const Row & row);
	void insert(const Row & row);
	void merge(const Table & table);

	void popFront();
	void popBack();
	void removeAt(int index);
	void remove(const Row & row);

	Row get(int index);
	int ref(const Row & value);

private:
	void runPrepend(memory::ArgList & args);
	void runAppend(memory::ArgList & args);
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

private:
	Table * table;
};


}  // namespace icL::context::object

Q_DECLARE_METATYPE(icL::context::object::SetPtr);

#endif  // icl_context_object_Set
