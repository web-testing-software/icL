#ifndef icL_memory_Set
#define icL_memory_Set

#include "functioncontainer.h"

#include <bits/shared_ptr.h>

#include <QLinkedList>
#include <QVariant>


namespace icL::memory {

using Row   = QLinkedList<QVariant>;
using Table = QLinkedList<Row>;

struct SetPtr
{
	std::shared_ptr<ParamList *> header;
	std::shared_ptr<Table *>     table;
};

struct SetObjPtr
{
	std::shared_ptr<ParamList *>     header;
	std::shared_ptr<Table::iterator> table;
};

}  // namespace icL::memory

Q_DECLARE_METATYPE(icL::memory::SetPtr);
Q_DECLARE_METATYPE(icL::memory::SetObjPtr);

#endif  // icL_memory_Set
