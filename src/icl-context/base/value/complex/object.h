#ifndef icL_context_value_Object
#define icL_context_value_Object

#include "../base/value.h"

#include <icl-memory/structures/set.h>

namespace icL::context::value {

class Object : public Value
{
public:
	/**
	 * @~english
	 * @brief Object calls the contructor of class Value
	 * @param il is a base contructor argument
	 * @param container is a base contructor argument
	 * @param varName is a base contructor argument
	 */
	Object(
	  memory::InterLevel * il, memory::DataState * container,
	  const QString & varName);

	/**
	 * @~english
	 * @brief Object calls the contructor of class Value
	 * @param il is a base contructor argument
	 * @param rvalue is a base contructor argument
	 * @param readonly is a base contructor argument
	 */
	Object(
	  memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);

	/**
	 * @~english
	 * @brief Object calls the contructor of class Value
	 * @param il is a base contructor argument
	 * @param getter is a base contructor argument
	 * @param setter is a base contructor argument
	 */
	Object(
	  memory::InterLevel * il, const QString & getter, const QString & setter);

	/**
	 * @~english
	 * @brief Object calls the contructor of class Value
	 * @param il is a base contructor argument
	 * @param Value is a base contructor argument
	 */
	Object(memory::InterLevel * il, const Value * const Value);

	/**
	 * @~english
	 * @brief has finds a property in object
	 * @param property is the name of propertu to find
	 * @return true if object contains the needed property, otherwise false
	 */
	bool has(const QString & property);

	/**
	 * @~english @brief method middle level function
	 * @~ @see has
	 */
	void runHas(memory::ArgList & args);

	// icL.context.Context interface
public:
	Context * runProperty(Prefix prefix, const QString & name) override;
	Context * runMethod(const QString & name, memory::ArgList & args) override;
};

}  // namespace icL::context::value

#endif  // icL_context_value_Object
