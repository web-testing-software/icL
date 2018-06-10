#ifndef icL_memory_Set
#define icL_memory_Set

#include "functioncontainer.h"

#include <memory>

#include <QLinkedList>
#include <QVariant>


namespace icL::memory {

using Table = QHash<QString, QVariantList>;

struct SetPtr
{
	std::shared_ptr<ParamList> header;

	std::shared_ptr<Table> table;
};

struct SetObjPtr
{
	SetPtr  set;
	QString key;
};

}  // namespace icL::memory

Q_DECLARE_METATYPE(icL::memory::SetPtr);
Q_DECLARE_METATYPE(icL::memory::SetObjPtr);

#endif  // icL_memory_Set
