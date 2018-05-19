#ifndef icl_context_object_List
#define icl_context_object_List

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

class List : public Object
{
public:
	List(memory::InterLevel * il, memory::DataState * container, const QString & varName);
	List(memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);
	List(memory::InterLevel * il, const QString & getter, const QString & setter);
	List(memory::InterLevel * il, const Object * const object);

	// static data
private:
	static const QHash<QString, void (List::*)()>                  properties;
	static const QHash<QString, void (List::*)(memory::ArgList &)> methods;

public:
	static const QHash<QString, void (List::*)()> initProperties();
	static const QHash<QString, void (List::*)(memory::ArgList &)>
	initMethods();

	// Properties
public:
	int length();

private:
	void runLength();

	// Methods
public:
	void prepend(const QString & value);
	void append(const QString & value);
	void insert(int index, const QString & value);
	void merge(const QStringList & List);

	void popFront();
	void popBack();
	void remove(int index);
	void removeOnce(const QString & value);
	void removeAll(const QString & value);


	QString get(int index);
	int     indexOf(const QString & value);
	int     lastIndexOf(const QString value);
	QString join(const QString & delimiter = "");

	double sumUp();
	double max();
	double min();

	bool logicAnd();
	bool logicOr();

private:
	void runPrepend(memory::ArgList & args);
	void runAppend(memory::ArgList & args);
	void runInsert(memory::ArgList & args);
	void runMerge(memory::ArgList & args);

	void runPopFront(memory::ArgList & args);
	void runPopBack(memory::ArgList & args);
	void runRemove(memory::ArgList & args);
	void runRemoveOnce(memory::ArgList & args);
	void runRemoveAll(memory::ArgList & args);

	void runGet(memory::ArgList & args);
	void runIndexOf(memory::ArgList & args);
	void runLastIndexOf(memory::ArgList & args);
	void runJoin(memory::ArgList & args);

	void runSumUp(memory::ArgList & args);
	void runMax(memory::ArgList & args);
	void runMin(memory::ArgList & args);

	void runLogicAnd(memory::ArgList & args);
	void runLogicOr(memory::ArgList & args);


	// Back-end
private:
	QString getFirst();

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
