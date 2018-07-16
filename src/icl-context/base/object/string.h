#ifndef icl_context_object_String
#define icl_context_object_String

#include "object.h"

namespace icL::context::object {

/**
 * \~english @brief The String class contains a string value of reference.
 */
class String : public Value
{
public:
	/**
	 * \~english
	 * @brief String calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param container is a base contructor argument
	 * @param varName is a base contructor argument
	 */
	String(memory::InterLevel * il, memory::DataState * container, const QString & varName);

	/**
	 * \~english
	 * @brief String calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param rvalue is a base contructor argument
	 * @param readonly is a base contructor argument
	 */
	String(memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);

	/**
	 * \~english
	 * @brief String calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param getter is a base contructor argument
	 * @param setter is a base contructor argument
	 */
	String(memory::InterLevel * il, const QString & getter, const QString & setter);

	/**
	 * \~english
	 * @brief String calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param object is a base contructor argument
	 */
	String(memory::InterLevel * il, const Value * const object);

	// Context interface
public:
	Context * runMethod(const QString & name, memory::ArgList & args) override;

	// Object interface
public:
	/**
	 * \~english @return memory.Type.String
	 */
	memory::Type type() const override;

	bool              toBool() override;
	int               toInt() override;
	double            toDouble() override;
	const QString     toString() override;
	const QStringList toList() override;
};

}  // namespace icL::context::object

#endif  // icl_context_object_String
