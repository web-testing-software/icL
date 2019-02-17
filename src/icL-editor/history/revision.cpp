#include "revision.h"

namespace icL::editor {

Revision * Revision::prev() {
    return m_prev;
}

Revision * Revision::next() {
    return m_next;
}

Revision * Revision::alt() {
    return m_alt;
}

void Revision::setPrev(Revision * prev) {
    m_prev = prev;
}

void Revision::setNext(Revision * next) {
    m_next = next;
}

void Revision::setAlt(Revision * alt) {
    m_alt = alt;
}

}  // namespace icL::editor
