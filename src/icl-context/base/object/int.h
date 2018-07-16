#ifndef icl_context_object_Int
#define icl_context_object_Int

#include "object.h"



namespace icL::context::object {

/**
 * \~english @brief The Int class contains a int value or reference.
 */
class Int : public Value
{
public:
	/**
	 * \~english
	 * @brief Int calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param container is a base contructor argument
	 * @param varName is a base contructor argument
	 */
	Int(memory::InterLevel * il, memory::DataState * container, const QString & varName);

	/**
	 * \~english
	 * @brief Int calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param rvalue is a base contructor argument
	 * @param readonly is a base contructor argument
	 */
	Int(memory::InterLevel * il, const QVariant & rvalue, bool readonly = false);

	/**
	 * \~english
	 * @brief Int calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param getter is a base contructor argument
	 * @param setter is a base contructor argument
	 */
	Int(memory::InterLevel * il, const QString & getter, const QString & setter);

	/**
	 * \~english
	 * @brief Int calls the contructor of class Object
	 * @param il is a base contructor argument
	 * @param object is a base contructor argument
	 */
	Int(memory::InterLevel * il, const Value * const object);

	// Context interface
public:
	Context * runMethod(const QString & name, memory::ArgList & args) override;

	// Object interface
public:
	/**
	 * \~english @return memory.Type.Int
	 */
	memory::Type type() const override;

	bool              toBool() override;
	int               toInt() override;
	double            toDouble() override;
	const QString     toString() override;
	const QStringList toList() override;
};

}  // namespace icL::context::object

#endif  // icl_context_object_Int
