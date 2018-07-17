#ifndef icL_memory_Set
#define icL_memory_Set

#include "../state/datastate.h"
#include "functioncontainer.h"

#include <memory>

#include <QLinkedList>
#include <QVariant>


namespace icL::memory {

using Table = QList<QVariantList>;

struct SetPtr
{
	std::shared_ptr<ParamList> header;

	std::shared_ptr<Table> table;
};

struct SetObjPtr
{
	SetPtr set;
	int    id = -1;
};

struct ObjectPtr
{
	std::shared_ptr<DataState> data;
};

}  // namespace icL::memory

Q_DECLARE_METATYPE(icL::memory::SetPtr);
Q_DECLARE_METATYPE(icL::memory::SetObjPtr);
Q_DECLARE_METATYPE(icL::memory::ObjectPtr);

#endif  // icL_memory_Set
