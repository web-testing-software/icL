#ifndef OBJECT_H
#define OBJECT_H

#include <context-base/context.h>

#include <icl-memory/state/datastate.h>


/**
 * vm
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
namespace vm::context::object {

class Object : public Context
{
public:
	/**
	 * @brief Object - construct a L-Value
	 * @param container - a DataState pointer
	 * @param varName - the name of var in container
	 */
	Object(memory::DataState* container, const QString& varName);
	/**
	 * @brief Object - constuct a R-Value
	 * @param rvalue - the value of object
	 * @param readonly - true restricts assigns
	 */
	Object(const QVariant& rvalue, bool readonly = false);
	/**
	 * @brief Object - construct a JS-Value
	 * @param getter - a getter string, eg. window.height
	 * @param setter - a setter string, eg. window.height = %1 (QString arg)
	 */
	Object(const QString& getter, const QString& setter);
	/**
	 * @brief Object - construct a object copy, used for coping values on
	 * function call
	 * @param object - pointer to object, which need to be copied
	 */
	Object(const Object* const object);

	virtual memory::Type type() const;

	virtual bool isRValue() const;
	virtual bool isReadOnly() const;
	virtual bool isLValue() const;
	virtual bool isLink() const;

	virtual QVariant getValue();
	virtual void     setValue(const QVariant& value);

	const QString& getVarName() const;

public:
	// Cast functions
	virtual bool              toBoolean() = 0;
	virtual int               toInt()     = 0;
	virtual double            toDouble()  = 0;
	virtual const QString     toString()  = 0;
	virtual const QStringList toList()    = 0;

private:
	void runToBoolean(memory::ArgList& args);
	void runToInt(memory::ArgList& args);
	void runToDouble(memory::ArgList& args);
	void runToString(memory::ArgList& args);
	void runToList(memory::ArgList& args);

protected:
	void sendWrongCast(const QString& to);
	void sendCastFailed(const QString& value, const QString& type);
	void runCast(const QString& name, memory::ArgList& args);

signals:
	void requestJsExecution(
	  const QString&                           str,
	  std::function<void(const QVariant& var)> feedback) const;

protected:
	// LValue
	memory::DataState* container = nullptr;
	QString            varName;

	// RValue
	QVariant rvalue;
	bool     readonly = false;

	// JsValue
	QString setter;
	QString getter;

	enum class Value { L, R, Js } value;

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool canBeAtEnd() const override;

	bool isResultative() const override;
};

}  // namespace vm::context::object

#endif  // OBJECT_H
