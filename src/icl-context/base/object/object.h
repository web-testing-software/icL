#ifndef icl_context_object_Object
#define icl_context_object_Object

#include "../context.h"

#include <icl-memory/state/datastate.h>


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

/**
 * \~english @brief The Object class is the base class for all classes in
 * context.object namespace
 */
class Object : public Context
{
public:
	/**
	 * @brief Object - construct a L-Value
	 * @param container - a DataState pointer
	 * @param varName - the name of var in container
	 */
	Object(
	  memory::InterLevel * il, memory::DataState * container,
	  const QString & varName);
	/**
	 * @brief Object - constuct a R-Value
	 * @param rvalue - the value of object
	 * @param readonly - true restricts assigns
	 */
	Object(
	  memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);
	/**
	 * @brief Object - construct a JS-Value
	 * @param getter - a getter string, eg. window.height
	 * @param setter - a setter string, eg. window.height = %1 (QString arg)
	 */
	Object(
	  memory::InterLevel * il, const QString & getter, const QString & setter);
	/**
	 * @brief Object - construct a object copy, used for coping values on
	 * function call
	 * @param object - pointer to object, which need to be copied
	 */
	Object(memory::InterLevel * il, const Object * const object);

	/**
	 * @brief ~Object is a default virtual destructor
	 */
	virtual ~Object() = default;

	// static

private:
	/**
	 * \~english @brief methods list of all variable
	 */
	static const QHash<QString, void (Object::*)(memory::ArgList &)> methods;

public:
	/**
	 * \~english
	 * @brief initMethods is the initial list of icL methods
	 * @return a list of pairs (name of property, pointer to Object.*)
	 */
	static const QHash<QString, void (Object::*)(memory::ArgList &)>
	initMethods();

public:
	/**
	 * @brief type returs the type of contained value
	 * @return the default value (memory.Type.Void)
	 */
	virtual memory::Type type() const;

	/**
	 * @brief getValue return the contained value
	 * @return the contained value
	 */
	virtual QVariant getValue();

	/**
	 * @brief setValue sets the contained value
	 * @param value is the value o set
	 */
	virtual void setValue(const QVariant & value);

	/**
	 * @brief getVarName is used for deugging
	 * @return the varName private variable value
	 * @warning use only from context.data.Assign
	 */
	const QString & getVarName() const;

public:
	/**
	 * @brief isRValue defines the value storange type
	 * @return true if value is stored in object, otherwise false
	 */
	virtual bool isRValue() const;

	/**
	 * @brief isReadOnly defined the mutable ability
	 * @return true if value is imutable, otherwise false
	 */
	virtual bool isReadOnly() const;

	/**
	 * @brief isLValue defines the mutable ability
	 * @return true if value is mutable, otherwise false
	 */
	virtual bool isLValue() const;

	/**
	 * @brief isLink defines the value storange type
	 * @return true if value is not stored in object, otherwise false
	 */
	virtual bool isLink() const;

	/**
	 * @brief ensureRValue copies the value to the container
	 * @return the new created icL object
	 */
	Object * ensureRValue();

private:
	/**
	 * \~english @brief method middle level function
	 * \~ @see isRValue
	 */
	void runIsRValue(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see isReadOnly
	 */
	void runIsReadOnly(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see isLValue
	 */
	void runisLValue(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see isLink
	 */
	void runIsLink(memory::ArgList & args);

	/**
	 * \~english @brief method middle level function
	 * \~ @see ensureRValue
	 */
	void runEnsureRValue(memory::ArgList & args);


public:
	// Cast functions

	/**
	 * @brief toBoolean casts contained value to bool
	 * @return casted value
	 */
	virtual bool toBoolean() = 0;

	/**
	 * @brief toInt casts contained value to int
	 * @return casted value
	 */
	virtual int toInt() = 0;

	/**
	 * @brief toDouble casts contained value to double
	 * @return casted value
	 */
	virtual double toDouble() = 0;

	/**
	 * @brief toString casts contained value to string
	 * @return casted value
	 */
	virtual const QString toString() = 0;

	/**
	 * @brief toList casts contained value to list
	 * @return casted value
	 */
	virtual const QStringList toList() = 0;

private:
	/**
	 * \~english @brief cast middle level function
	 * \~ @see toBoolean
	 */
	void runToBoolean(memory::ArgList & args);

	/**
	 * \~english @brief cast middle level function
	 * \~ @see toInt
	 */
	void runToInt(memory::ArgList & args);

	/**
	 * \~english @brief cast middle level function
	 * \~ @see toDouble
	 */
	void runToDouble(memory::ArgList & args);

	/**
	 * \~english @brief cast middle level function
	 * \~ @see toString
	 */
	void runToString(memory::ArgList & args);

	/**
	 * \~english @brief cast middle level function
	 * \~ @see toList
	 */
	void runToList(memory::ArgList & args);

protected:
	/**
	 * @brief sendWrongCast sends to vm an exception
	 * @param to is the requested type
	 */
	void sendWrongCast(const QString & to);

	/**
	 * @brief sendCastFailed sends to vm an exception
	 * @param value is the wrong value
	 * @param type is the requested type
	 */
	void sendCastFailed(const QString & value, const QString & type);


	/**
	 * \~english @brief cast middle level function
	 */
	void runCast(const QString & name, memory::ArgList & args);

	/**
	 * @brief parseToBool parses string to bool
	 * @param str is the string to parse
	 * @return (parsed value, success status)
	 */
	std::pair<bool, bool> parseToBool(const QString & str);

	/**
	 * @brief parseToInt parses string to int
	 * @param str is the string to parse
	 * @return (parsed value, success status)
	 */
	std::pair<int, bool> parseToInt(const QString & str);

	/**
	 * @brief parseToDouble parses string to double
	 * @param str is the string to parse
	 * @return (parsed value, success status)
	 */
	std::pair<double, bool> parseToDouble(const QString & str);

protected:
	// LValue
	memory::DataState * container = nullptr;  ///< Each l value has a container
	QString             varName;  ///< Each l value has a variable name

	// RValue
	QVariant rvalue; ///< The value of r value
	bool     readonly = false; ///< The r/o poperty

	// JsValue
	QString setter; ///< the setter of js value
	QString getter; ///< the getter of js value

	/**
	 * @brief The Value enum decribes the value type
	 */
	enum class Value { L, R, Js } value; ///< The type of contained value

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool canBeAtEnd() const override;

	Context * runMethod(const QString & name, memory::ArgList & args) override;
	bool      isResultative() const override;
};

}  // namespace icL::context::object

#endif  // icl_context_object_Object
