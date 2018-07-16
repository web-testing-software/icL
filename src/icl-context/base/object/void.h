#ifndef icl_context_object_Void
#define icl_context_object_Void

#include "object.h"


namespace icL::context::object {

/**
 * \~english @brief The Void class is an empty container or a new variable.
 */
class Void : public Value
{
public:
	/**
	 * \~english
	 * @brief Void calls the contructor of class Object
	 * @param il is a base contructor argument
	 */
	Void(memory::InterLevel * il);

	/**
	 * \~english
	 * @brief Void calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param container is a base contructor argument
	 * @param varName is a base contructor argument
	 */
	Void(
	  memory::InterLevel * il, memory::DataState * container,
	  const QString & varName);

	/**
	 * \~english
	 * @brief Void calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param getter is a base contructor argument
	 * @param setter is a base contructor argument
	 */
	Void(
	  memory::InterLevel * il, const QString & getter, const QString & setter);

	// Context interface
public:
	Context * runProperty(Prefix prefix, const QString & name) override;
	Context * runMethod(const QString & name, memory::ArgList & args) override;

	// Object interface
public:
	bool              toBool() override;
	int               toInt() override;
	double            toDouble() override;
	const QString     toString() override;
	const QStringList toList() override;
};

}  // namespace icL::context::object

#endif  // icl_context_object_Void
