#ifndef LIST_H
#define LIST_H

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
	List(memory::DataState * container, const QString & varName);
	List(const QVariant & rvalue, bool readonly = false);
	List(const QString & getter, const QString & setter);
	List(const Object * const object);

	// Properties
public:
	int length();

protected:
	void runGetLength();

	// Methods
public:
	void prepend(const QString & value);
	void append(const QString & value);
	void insert(int index, const QString & value);
	void merge(const QStringList & list);

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

#endif  // LIST_H
