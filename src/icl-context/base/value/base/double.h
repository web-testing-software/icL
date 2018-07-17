#ifndef icl_context_value_Double
#define icl_context_value_Double

#include "value.h"


namespace icL::context::value {

/**
 * \~english @brief The Double class contains a double value or reference.
 */
class Double : public Value
{
public:
	/**
	 * \~english
	 * @brief Double calls the contructor of class Value
	 * @param il is a base contructor argument
	 * @param container is a base contructor argument
	 * @param varName is a base contructor argument
	 */
	Double(
	  memory::InterLevel * il, memory::DataState * container,
	  const QString & varName);

	/**
	 * \~english
	 * @brief Double calls the contructor of class Value
	 * @param il is a base contructor argument
	 * @param rvalue is a base contructor argument
	 * @param readonly is a base contructor argument
	 */
	Double(
	  memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);

	/**
	 * \~english
	 * @brief Double calls the contructor of class Value
	 * @param il is a base contructor argument
	 * @param getter is a base contructor argument
	 * @param setter is a base contructor argument
	 */
	Double(
	  memory::InterLevel * il, const QString & getter, const QString & setter);

	/**
	 * \~english
	 * @brief Double calls the contructor of class Value
	 * @param il is a base contructor argument
	 * @param object is a base contructor argument
	 */
	Double(memory::InterLevel * il, const Value * const object);

	// Context interface
public:
	Context * runMethod(const QString & name, memory::ArgList & args) override;

	// Object interface
public:
	/**
	 * \~english @return memory.Type.Double
	 */
	memory::Type type() const override;

	bool              toBool() override;
	int               toInt() override;
	double            toDouble() override;
	const QString     toString() override;
	const QStringList toList() override;
};

}  // namespace icL::context::value

#endif  // icl_context_value_Double
