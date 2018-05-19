#ifndef icL_memory_DataState
#define icL_memory_DataState

#include "../structures/type.h"

#include <QMap>
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

/**
 * @brief The DataState class - interface for stack state and memory state
 */
class DataState
{
public:
	DataState();

	// Functions to add data to containers
	void setValue(const QString & name, const QVariant & value);

	// Functions to access data and metadata from containers
	bool     contains(const QString & name);
	Type     getType(const QString & name);
	bool     checkType(const QString & name, Type & type);
	QVariant getValue(const QString & name);

private:
	// Data container
	QVariantMap dataMap;
};

}  // namespace icL::memory

#endif  // icL_memory_DataState
