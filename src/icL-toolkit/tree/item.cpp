#include "item.h"

#include "../utils/remotecall.h"
#include "folder.h"

namespace icL::toolkit::tree {

Item::Item(Item * parent) {
    m_parent = parent;
}

Item::~Item() {
    clear();
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

void Item::clear() {
    for (auto * ptr : getActionsList()) {
        delete ptr;
    }
}

}  // namespace icL::toolkit::tree
