#ifndef icL_memory_Type
#define icL_memory_Type

#include <QString>
#include <QVariant>

/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '-> memory
 */
namespace icL::memory {

enum class Type {
	Void,
	Boolean,
	Int,
	Double,
	String,
	List,
	Element,
	Set,
	SetObj
};

QString typeToString(Type type);

Type variantTypeToType(const QVariant & var);

}  // namespace icL::memory

#endif  // icL_memory_Type
