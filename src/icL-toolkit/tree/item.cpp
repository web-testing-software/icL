#include "item.h"

#include "folder.h"

namespace icL::toolkit::tree {

Item::Item(Item * parent) {
	m_parent = parent;
}

int Item::selfIndex() {
	if (m_parent != nullptr) {
		return dynamic_cast<Folder *>(m_parent)->children.indexOf(this);
	}

	return 0;
}

Item * Item::parent() {
	return m_parent;
}

}  // namespace icL::toolkit::tree
