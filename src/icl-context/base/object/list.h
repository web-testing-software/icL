#ifndef icl_context_value_List
#define icl_context_value_List

#include "value.h"


namespace icL::context::value {

/**
 * \~english @brief The List class contains a list value or reference.
 */
class List : public Value
{
public:
	/**
	 * \~english
	 * @brief List calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param container is a base contructor argument
	 * @param varName is a base contructor argument
	 */
	List(
	  memory::InterLevel * il, memory::DataState * container,
	  const QString & varName);

	/**
	 * \~english
	 * @brief List calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param rvalue is a base contructor argument
	 * @param readonly is a base contructor argument
	 */
	List(
	  memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);

	/**
	 * \~english
	 * @brief List calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param getter is a base contructor argument
	 * @param setter is a base contructor argument
	 */
	List(
	  memory::InterLevel * il, const QString & getter, const QString & setter);

	/**
	 * \~english
	 * @brief List calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param object is a base contructor argument
	 */
	List(memory::InterLevel * il, const Value * const object);

	// static data
private:
	/**
	 * \~english @brief properties list of &lt;list&gt;
	 */
	static const QHash<QString, void (List::*)()> properties;

	/**
	 * \~english @brief methods list of &lt;list&gt;
	 */
	static const QHash<QString, void (List::*)(memory::ArgList &)> methods;

public:
	/**
	 * \~english
	 * @brief initProperties is the initial list of icL properties
	 * @return a list of pairs (name of property, pointer to List.*)
	 */
	static const QHash<QString, void (List::*)()> initProperties();

	/**
	 * \~english
	 * @brief initMethods is the initial list of icL methods
	 * @return a list of pairs (name of property, pointer to List.*)
	 */
	static const QHash<QString, void (List::*)(memory::ArgList &)>
	initMethods();

	// Properties
public:
	/**
	 * \~english
	 * @brief length returns the number of strings in list
	 * @return the count of strings in list
	 */
	int length();

private:
	/**
	 * \~english @brief property middle level function
	 * \~ @see length
	 */
	void runLength();

	// Methods
public:
	/**
	 * \~english
	 * @brief prepend inserts a new string at begin of list
	 * @param value is the value to insert
	 * @see append and insert
	 */
	void prepend(const QString & value);

	/**
	 * \~english
	 * @brief append inserts a new string at end of list
	 * @param value is the value to insert
	 * @see prepend and insert
	 */
	void append(const QString & value);

	/**
	 * \~english
	 * @brief insert inserts a value in needed position
	 * @param index is the index of the new value
	 * @param value is the new value to insert
	 * @see prepend and append
	 */
	void insert(int index, const QString & value);

	/**
	 * \~english
	 * @brief merge adds all strings of list argument to current list
	 * @param list is the list to merge
	 */
	void merge(const QStringList & list);

	/**
	 * \~english
	 * @brief popFront removes the first element from list
	 * @see popBack, remove, removeOnce and removeAll
	 */
	void popFront();

	/**
	 * \~english
	 * @brief popBack removes the last element from list
	 * @see popBack, remove, removeOnce and removeAll
	 */
	void popBack();

	/**
	 * \~english
	 * @brief remove removes the string with index index
	 * @param index is the index of element to remove
	 * @see popFront, popBack, removeOnce and removeAll
	 */
	void remove(int index);

	/**
	 * \~english
	 * @brief removeOnce removes the first string in list with value value
	 * @param value is the value to match
	 * @see popFront, popBack, remove and removeAll
	 */
	void removeOnce(const QString & value);

	/**
	 * \~english
	 * @brief removeAll removes all strings in list with value value
	 * @param value is the value to match
	 * @see popFront, popBack, remove and removeOnce
	 */
	void removeAll(const QString & value);

	/**
	 * \~english
	 * @brief get returns the string from list with index index
	 * @param index is the index of returned string
	 * @return the string with index index
	 */
	QString get(int index);

	/**
	 * \~english
	 * @brief indexOf returns the index of first string which matches the value
	 * @param value is the value to match
	 * @return index or -1 if not found
	 * @see lastIndexOf
	 */
	int indexOf(const QString & value);

	/**
	 * \~english
	 * @brief lastIndexOf return the index of last string which matches the
	 * value
	 * @param value is the value to match
	 * @return index or -1 if not found
	 * @see indexOf
	 */
	int lastIndexOf(const QString value);

	/**
	 * \~english
	 * @brief join concatenates all strings of list
	 * @param delimiter of strings in the getted string
	 * @return the result of concatenation
	 */
	QString join(const QString & delimiter = "");

	/**
	 * \~english
	 * @brief sumUp casts to double each string and sums the getted numbers
	 * @return the sum of numbers from list
	 * @see max and min
	 */
	double sumUp();

	/**
	 * \~english
	 * @brief max casts to double each string and finds the maximum
	 * @return the maximum of numbers from list
	 * @see sumUp and min
	 */
	double max();

	/**
	 * \~english
	 * @brief min casts to double each string and finds the minimum
	 * @return the minimum of numbers from list
	 * @see sumUp and max
	 */
	double min();

	/**
	 * \~english
	 * @brief logicAnd casts to bool each string and aplicate disjunction on
	 * values
	 * @return the result of disjunction
	 * @see logicOr
	 */
	bool logicAnd();

	/**
	 * \~english
	 * @brief logicAnd casts to bool each string and aplicate conjunction on
	 * values
	 * @return the result of conjunction
	 * @see logicAnd
	 */
	bool logicOr();

private:
	/**
	 * \~english @brief method middle level function
	 * \~ @see prepend
	 */
	void runPrepend(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see append
	 */
	void runAppend(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see insert
	 */
	void runInsert(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see merge
	 */
	void runMerge(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see popFront
	 */
	void runPopFront(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see popBack
	 */
	void runPopBack(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see remove
	 */
	void runRemove(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see removeOnce
	 */
	void runRemoveOnce(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see removeAll
	 */
	void runRemoveAll(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see get
	 */
	void runGet(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see indexOf
	 */
	void runIndexOf(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see lastIndexOf
	 */
	void runLastIndexOf(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see join
	 */
	void runJoin(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see sumUp
	 */
	void runSumUp(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see max
	 */
	void runMax(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see min
	 */
	void runMin(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see logicAnd
	 */
	void runLogicAnd(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see logicOr
	 */
	void runLogicOr(memory::ArgList & args);


	// Back-end
private:
	/**
	 * \~english
	 * @brief getFirst returns the first element of list
	 * @return the first element of list
	 * @throw errors.EmptyList if list id empty
	 * @throw errors.MultipleValues if list contains more than one item
	 */
	QString getFirst();

	// Context interface
public:
	Context * runProperty(Prefix prefix, const QString & name) override;
	Context * runMethod(const QString & name, memory::ArgList & args) override;

	// Object interface
public:
	memory::Type type() const override;

	bool              toBool() override;
	int               toInt() override;
	double            toDouble() override;
	const QString     toString() override;
	const QStringList toList() override;
};

}  // namespace icL::context::value

#endif  // icl_context_value_List
