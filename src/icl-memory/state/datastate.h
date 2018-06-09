#ifndef icL_memory_DataState
#define icL_memory_DataState

#include "../structures/type.h"

#include <QMap>
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

class DataStateInterface
{
	virtual void setValue(const QString & name, const QVariant & value) = 0;

	virtual bool     contains(const QString & name)               = 0;
	virtual Type     getType(const QString & name)                = 0;
	virtual bool     checkType(const QString & name, Type & type) = 0;
	virtual QVariant getValue(const QString & name)               = 0;
};

/**
 * @brief The DataState class - interface for stack state and memory state,
 * contains common functions
 */
class DataState : public DataStateInterface
{
public:
	DataState();

	// Functions to add data to containers
	void setValue(const QString & name, const QVariant & value) override;

	// Functions to access data and metadata from containers
	bool     contains(const QString & name) override;
	Type     getType(const QString & name) override;
	bool     checkType(const QString & name, Type & type) override;
	QVariant getValue(const QString & name) override;

private:
	// Data container
	QVariantMap dataMap;
};

}  // namespace icL::memory

#endif  // icL_memory_DataState
