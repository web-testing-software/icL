#ifndef icl_context_object_Set
#define icl_context_object_Set

#include "object.h"

#include <icl-memory/structures/set.h>



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

	void appplicate(const QList<QStringList> & list);
	void insertField(const QString & name, const QVariant & value);
	void removeField(const QString & name);
	void concatLists(const QString & name, const QString & separator);

	void insert(const QVariantList & row);
	void merge(const memory::SetPtr &set2);
	void remove(const QVariantList & row);
	void removeAt(int index);
	void clear();

	memory::SetObjPtr at(int index);

private:
	void runApplicate(memory::ArgList & args);
	void runInsertField(memory::ArgList & args);
	void runRemoveField(memory::ArgList & args);
	void runConcatLists(memory::ArgList & args);

	void runInsert(memory::ArgList & args);
	void runMerge(memory::ArgList & args);
	void runRemove(memory::ArgList & args);
	void runRemoveAt(memory::ArgList & args);
	void runClear(memory::ArgList & args);

	void runAt(memory::ArgList & args);

	// Back-end
	bool checkRow(const memory::SetPtr & set, const QVariantList & row);
	int indexOf(const QString & name, const memory::SetPtr & set);
	bool isSetType(memory::Type type);

private:
	// Context interface
public:
	Context * runProperty(Prefix prefix, const QString & name) override;
	Context * runMethod(const QString & name, memory::ArgList & args) override;

	// Object interface
public:
	memory::Type type() const override;

	bool   toBool() override;
	int    toInt() override;
	double toDouble() override;

	const QString     toString() override;
	const QStringList toList() override;
};


}  // namespace icL::context::object


#endif  // icl_context_object_Set
