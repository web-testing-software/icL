#ifndef icL_memory_Type
#define icL_memory_Type

#include <QString>
#include <QVariant>

/**
 *  icL
 *  |- app
 *	|- context
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
 *  '- @namespace memory
 */
namespace icL::memory {

enum class Type { Void, Boolean, Int, Double, String, List, Element };

QString typeToString(Type type);

Type variantTypeToType(QVariant::Type type);

}  // namespace icL::memory

#endif  // icL_memory_Type
